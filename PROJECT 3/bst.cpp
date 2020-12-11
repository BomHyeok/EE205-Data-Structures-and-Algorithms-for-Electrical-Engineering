#include "bst.h"
#include <cassert>
#include <iostream>

using namespace std;

//overall
//PE : parent entry
//GPE : grandparent entry
//GGPE : grand grandparent entry
//SE : sibling entry
//UE : uncle entry
//RE : right child entry
//Le : left child entry

void IntBST::printrecur(IntEntry* E) {
	if((*E).left() != NULL) {
		printrecur((*E).left());
	}
	
	if((*E).color() == 0) {
		std::cout << (*E).key() << " " << (*E).isRoot() << " RED" << std::endl;
	}
	else if((*E).color() == 1) {
		std::cout << (*E).key() << " " << (*E).isRoot() << " BLACK" << std::endl;
	}
	
	if((*E).parent() == NULL) {
		std::cout << "parent : NULL" << std::endl;
	}
	else {
		std::cout << "parent : " << (*(*E).parent()).key() << std::endl;
	}
	
	if((*E).left() == NULL) {
		std::cout << "left : NULL" << std::endl;
	}
	else {
		std::cout << "left : " << (*(*E).left()).key() << std::endl;
	}

	if((*E).right() == NULL) {
		std::cout << "right : NULL" << std::endl;
	}
	else {
		std::cout << "right : " << (*(*E).right()).key() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;

	if((*E).right() != NULL) {
		printrecur((*E).right());
	}
	return;
}	
// print all of entry inorder way
void IntBST::printall() {
	IntEntry *E = T.getRoot();
	printrecur(E);
	std::cout << std::endl;
	return;
}
//////////////////////////////////////////////////////////////////////////
// Implementation of IntBST
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
int IntBST::findRecursion(int k, IntEntry *E) {
	int n = 0;
	if((*E).left() != NULL) {
		n += findRecursion(k, (*E).left());
	}
	if((*E).key() == k) {
		n ++;
	}
	if((*E).right() != NULL) {
		n += findRecursion(k, (*E).right());
	}
	return n;
}
// find number of entries that have key k in inorder way
int IntBST::find(int k)
{
	IntEntry* R = T.getRoot();
			
	return findRecursion(k, R);
}
//////////////////////////////////////////////////////////////////////////
void IntBST::insert(int k)
{
	int n = 0;

	// if tree is empty, entry should be thr root
	if(T.empty()) {
		IntEntry* E = new IntEntry(k, 0);
		(*E).setColor(IntEntry::BLACK);
		T.setRoot(E);
		cnt++;
		return;
	}
	
	IntEntry* R = T.getRoot();

	while(R) {
		if((*R).key() <= k) {
			if((*R).right() == NULL) {
				IntEntry* E = new IntEntry(k,1);
				(*E).setParent(R);
				(*R).setRight(E);
				cnt++;
				return;
			}
			R = (*R).right();
			n = 1;
		}
		else if((*R).key() > k) {
			if((*R).left() == NULL) {
				IntEntry* E = new IntEntry(k,1);
				(*E).setParent(R);
				(*R).setLeft(E);
				cnt++;
				return;
			}
			R = (*R).left();
			n = 0;
		}
	}	
	return;	
		
}

//////////////////////////////////////////////////////////////////////////
bool IntBST::remove(int k)
{
	int n = 0;
	if(T.empty()) { 
		return false;
	}

	IntEntry* R = T.getRoot();
	
	// if root entry has a key k
	if((*R).key() == k) { 
		if((*R).isExternal()) { 
			T.setRoot(NULL);
			delete R;
			cnt--;
			return true;
		}
		if((*R).right() == NULL) {
			IntEntry* E = (*R).left();
			(*E).setParent(NULL);
			(*E).setValue(0);
			T.setRoot(E);
			delete R;
			cnt--;
			return true;
		}
		if((*R).left() == NULL) {
			IntEntry* E = (*R).right();
			(*E).setParent(NULL);
			(*E).setValue(0);	
			T.setRoot(E);
			delete R;
			cnt--;
			return true;
		}	
		
		// the smallest entry of right sub tree will replace
		IntEntry* E = (*R).right();

		int m = 0;

		while((*E).left()) {
			E = (*E).left();
			m++;
		}

		if(m == 0) {
			(*E).setLeft((*R).left());
			(*(*R).left()).setParent(E);
			(*E).setValue(0);
			T.setRoot(E);
			delete R;
			cnt--;
			return true;
		}

		if((*E).isInternal()) {
			(*(*E).right()).setParent((*E).parent());
		}
		(*(*E).parent()).setLeft((*E).right());
		(*E).setParent(NULL);
		(*E).setLeft((*R).left());
		(*E).setRight((*R).right());
		(*(*R).left()).setParent(E);
		(*(*R).right()).setParent(E);
		(*E).setValue(0);
		T.setRoot(E);
		delete R;
		cnt--;
		return true;
	}
	else { 	
		while(R) {
			if((*R).key() < k) {
				R = (*R).right();
				n = 1;
			}
			else if((*R).key() > k) {
				R = (*R).left();
				n = 0;
			}
			else {
				break;

			}
		}
		if(R == NULL) {
			return false;
		}

		if((*R).isExternal()) {	
			IntEntry* E = (*R).parent();
			if(n == 1)
				(*E).setRight(NULL);
			else if(n == 0)
				(*E).setLeft(NULL);
			delete R;
			cnt--;
			return true;
		}

		if((*R).left() == NULL) {
			IntEntry* E = (*R).right();
			IntEntry* PE = (*R).parent();
			(*E).setParent(PE);
			if(n == 1) {
				(*PE).setRight(E);
			}
			else if(n == 0) {
				(*PE).setLeft(E);
			}
			delete R;
			cnt--;
			return true;
		}	

		if((*R).right() == NULL) {
			IntEntry* E = (*R).left();
			IntEntry* PE = (*R).parent();
			(*E).setParent(PE);
			if(n == 1) {
				(*PE).setRight(E);
			}
			else if(n == 0) {
				(*PE).setLeft(E);
			}
			delete R;
			cnt--;
			return true;
		}
		// the smallest entry of right sub tree will replace
		IntEntry* E = (*R).right();

		int m = 0;

		while((*E).left()) {
			E = (*E).left();
			m++;
		}

		if(m == 0) {
			(*E).setParent((*R).parent());
			(*E).setLeft((*R).left());
			if(n == 1) {
				(*(*R).parent()).setRight(E);
				(*(*R).left()).setParent(E);
			}
			else if(n == 0){
				(*(*R).parent()).setLeft(E);
				(*(*R).left()).setParent(E);
			}
			delete R;
			cnt--;
			return true;
		}

		if((*E).isInternal()) {
			(*(*E).right()).setParent((*E).parent());
		}
		(*(*E).parent()).setLeft((*E).right());
		(*E).setParent((*R).parent());
		(*E).setLeft((*R).left());
		(*E).setRight((*R).right());
		if(n == 1) {
			(*(*R).parent()).setRight(E);
			(*(*R).left()).setParent(E);
			(*(*R).right()).setParent(E);
		}
		else if(n == 0){
			(*(*R).parent()).setLeft(E);
			(*(*R).left()).setParent(E);
			(*(*R).right()).setParent(E);
		}
		delete R;
		cnt--;
		return true;
	}
	// not implemented
//	assert(0);
//	return true;
}

//////////////////////////////////////////////////////////////////////////
int IntBST::countRecursion(int k1, int k2, IntEntry* E, int count)
{
	if(E == NULL) {
		return count;
	}

	count = countRecursion(k1, k2, (*E).left(), count);

	if((*E).key() >= k1 && (*E).key() <= k2) {
		count ++;
	}

	count = countRecursion(k1, k2, (*E).right(), count);

	return count;
}
// count number of entries in the range
int IntBST::countRange(int k1, int k2)
{
	int count = 0;	
	IntEntry* R = T.getRoot();
	//int count = 0;

	if(T.empty()) {
		return 0;
	}
	if(k1 < k2) {
		return countRecursion(k1, k2, R, count);
	}
	if(k1 > k2) {
		return countRecursion(k2, k1, R, count);
	}
	if(k1 == k2) {
		return find(k1);
	}
	
	// not implemented
	//assert(0);
	return -1;
}

//////////////////////////////////////////////////////////////////////////
// Implementation of IntRBTree
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

void IntRBTree::restructuring(int m, IntEntry *E, IntEntry *PE, IntEntry *GPE)
{
	IntEntry* GGPE = (*GPE).parent();
	IntEntry* ER = (*E).right();
	IntEntry* EL = (*E).left();
	int n, l;
	
	// n = 1 : E is right child of PE
	// n = 0 : E is left child of PE
	if((*PE).key() < (*E).key()) {
		n = 1;	
	}		
	else if((*PE).key() > (*E).key()) {	
		n = 0;	
	}		
	else {	
		n = 1;		
	}
	
	// n = 1 : GPE is right child of GGPE
	// n = 0 : GPE is left child of GGPE
	if(GGPE != NULL) {
	if((*GGPE).key() < (*GPE).key()) {
		l = 1;	
	}		
	else if((*GGPE).key() > (*GPE).key()) {	
		l = 0;	
	}		
	else {	
		if((*GGPE).key() < (*PE).key()) {	
			l = 1;
		}			
		else if((*GGPE).key() > (*PE).key()) {	
			l = 0;
		}
		else {		
			if((*GGPE).left() == NULL)
				l = 1;
			else if((*GGPE).right() == NULL)			
				l = 0;
			else if((*(*GGPE).left()).key() != (*GPE).key() && (*(*GGPE).right()).key() == (*GPE).key())			
				l = 1;
			else if((*(*GGPE).right()).key() != (*GPE).key() && (*(*GGPE).left()).key() == (*GPE).key())
				l = 0;
			else		
				l = 1;	
		}
	}
	}
	
	// 4 cases : n is 0 or 1 / m is 0 or 1
	if(n == 1) {
		IntEntry* SE = (*PE).left();
		if(m == 1) {
			(*PE).setColor(IntEntry::BLACK);
			(*GPE).setColor(IntEntry::RED);
			(*PE).setParent(GGPE);
			(*PE).setLeft(GPE);
			if((*GPE).isRoot()) {
				(*GPE).setValue(1);
				(*PE).setValue(0);
				(*PE).setParent(NULL);
				T.setRoot(PE);
			}
			else if(l == 1) {
				(*GGPE).setRight(PE);
			}
			else if(l == 0) {
				(*GGPE).setLeft(PE);
			}

			if(SE != NULL) {
				(*SE).setParent(GPE);
				(*GPE).setRight(SE);
			}
			else {
				(*GPE).setRight(NULL);
			}
			(*GPE).setParent(PE);
			return;
		}
		if(m == 0) {
			(*E).setColor(IntEntry::BLACK);
			(*GPE).setColor(IntEntry::RED);
			(*E).setParent(GGPE);
			(*E).setRight(GPE);
			(*E).setLeft(PE);
			if((*GPE).isRoot()) {
				(*GPE).setValue(1);
				(*E).setValue(0);
				(*E).setParent(NULL);
				T.setRoot(E);
			}
			else if(l == 1) {
				(*GGPE).setRight(E);
			}
			else if(l == 0) {
				(*GGPE).setLeft(E);
			}
			(*PE).setParent(E);
			(*PE).setRight(EL);
			if(EL != NULL) {
				(*EL).setParent(PE);
			}
			(*GPE).setParent(E);
			(*GPE).setLeft(ER);
			if(ER != NULL) {
				(*ER).setParent(GPE);
			}

			return;
		}
	}
	if(n == 0) {
		IntEntry* SE = (*PE).right();
		if(m == 1) {
			(*E).setColor(IntEntry::BLACK);
			(*GPE).setColor(IntEntry::RED);
			(*E).setParent(GGPE);
			(*E).setRight(PE);
			(*E).setLeft(GPE);
			if((*GPE).isRoot()) {
				(*GPE).setValue(1);
				(*E).setValue(0);
				(*E).setParent(NULL);
				T.setRoot(E);
			}
			else if(l == 1) {
				(*GGPE).setRight(E);
			}
			else if(l == 0) {
				(*GGPE).setLeft(E);
			}
			(*PE).setParent(E);
			(*PE).setLeft(ER);
			if(ER != NULL) {
				(*ER).setParent(PE);
			}
			(*GPE).setParent(E);
			(*GPE).setRight(EL);
			if(EL != NULL) {
				(*EL).setParent(GPE);
			}
			return;
		}
		if(m == 0) {
			(*PE).setColor(IntEntry::BLACK);
			(*GPE).setColor(IntEntry::RED);
			(*PE).setParent(GGPE);
			(*PE).setRight(GPE);
			if((*GPE).isRoot()) {
				(*GPE).setValue(1);
				(*PE).setValue(0);
				(*PE).setParent(NULL);
				T.setRoot(PE);
			}
			else if(l == 1) {
				(*GGPE).setRight(PE);
			}
			else if(l == 0) {
				(*GGPE).setLeft(PE);
			}

			if(SE != NULL) {
				(*SE).setParent(GPE);
				(*GPE).setLeft(SE);
			}
			else {
				(*GPE).setLeft(NULL);
			}
			(*GPE).setParent(PE);
			return;
		}
	}

}
// if GPE is root, do not change the color
void IntRBTree::recoloring(IntEntry *E, IntEntry *PE, IntEntry *GPE, IntEntry *UE)
{
	(*PE).setColor(IntEntry::BLACK);
	(*UE).setColor(IntEntry::BLACK);
	if(!(*GPE).isRoot()) {
		(*GPE).setColor(IntEntry::RED);
	}
	return;
}

void IntRBTree::insert(int k)
{
	IntBST::insert(k);
	int n = 0;
	int m = 0;

		IntEntry* R = T.getRoot();

		// find entry that i just inserted by IntBST::insert(k)
		while(R) {
			if((*R).key() <= k) {
				if((*R).isExternal()) {
					break;
				}
				R = (*R).right();
				n = 1;
			}
			else if((*R).key() > k) {
				R = (*R).left();
				n = 0;
			}

		}


		while((*R).color() == IntEntry::RED) {
			// if R is root
			if((*R).parent() == NULL) {
				break;
			}
			// if PR is root
			else if((*(*R).parent()).parent() == NULL) {
				break;
			}

			else if((*(*R).parent()).color() == IntEntry::RED) {
				IntEntry* PE = (*R).parent();
				IntEntry* GPE = (*PE).parent();
				IntEntry* UE;
				
				if((*GPE).key() < (*PE).key()) {
					UE = (*GPE).left();
					m = 1;
				}
				else if((*GPE).key() > (*PE).key()) {
					UE = (*GPE).right();
					m = 0;
				}
				else {
					if((*GPE).key() < (*R).key()) {
						UE = (*GPE).left();
						m = 1;
					}
					else if((*GPE).key() > (*R).key()) {
						UE = (*GPE).right();
						m = 0;
					}
					else {
						if((*GPE).left() == NULL) {
							UE = (*GPE).left();
							m = 1;
						}
						else if((*GPE).right() == NULL) {
							UE = (*GPE).right();
							m = 0;
						}
						else if((*(*GPE).left()).key() != (*PE).key() && (*(*GPE).right()).key() == (*PE).key()) {
							UE = (*GPE).left();
							m = 1;
						}
						else if((*(*GPE).right()).key() != (*PE).key() && (*(*GPE).left()).key() == (*PE).key()) {
							UE = (*GPE).right();
							m = 0;
						}
						else {
							UE = (*GPE).left();
							m = 1;
						}
					}
				}
				if(UE == NULL || (*UE).color() == IntEntry::BLACK) {
					restructuring(m, R, PE, GPE);
					break;
				}	
				else if(UE != NULL && (*UE).color() == IntEntry::RED) {
					recoloring(R, PE, GPE, UE);
					R = GPE;
				}
			}
			else break;
		}
	return;
	// not implemented
	//assert(0);
}

//////////////////////////////////////////////////////////////////////////
bool IntRBTree::remove(int k)
{
  // not implemented, return value is true for the test file
  //assert(false);
	return true;
}
