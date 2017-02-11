#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<limits>
#include<cstdlib>
#include<random>
#include<chrono>


/// Templated Skip List emualating an unordered set ///


using namespace std;

template<class T> class node{
	public:
	node<T> *prev,*next,*above,*below;
	node<T>(int val,node<T> *prev, node<T> *next,node<T> *above, node<T> *below){
		this->value = val; 
		this->prev = prev;
		this->next = next;
		this->above = above;
		this-> below = below;
	}
	T getval(){
		return value;
	}
private:
	T value;
};

template<class T> class SkipList{								//Distinct elements only (Emulates a set)
private:
	node<T> *topleftabove,*topright,*bottomleft,*bottomright;
	int max_height;
public:
	SkipList<T>(int max_height){
		topleftabove = new node<T>(numeric_limits<T>::min(),NULL,NULL,NULL,NULL);
		topright = new node<T>(numeric_limits<T>::max(),topleftabove,NULL,NULL,NULL);
		topleftabove->next = topright;
		node<T>* upleft = topleftabove;
		node<T>* upright = topright;
		this->max_height = max_height;
		for(int i=0;i<max_height;i++){
			node<T>* temp1 = new node<T>(numeric_limits<T>::min(),NULL,NULL,upleft,NULL);
			node<T>* temp2 = new node<T>(numeric_limits<T>::max(),temp1,NULL,upright,NULL);
			temp1->next = temp2;
			upleft->below = temp1;
			upright->below = temp2;
			upleft = temp1;
			upright = temp2;
		}
		bottomleft = upleft;
		bottomright = upright;
	}
	node<T>* skipSearch(T target){
		//cout<<"skipSearch starting on value "<<target<<endl;
		node<T>* p = topleftabove;
		while(p->below!=NULL){
			//cout<<p<<" "<<p->getval()<<endl;
			p=p->below;
			while(p->next!=NULL && target >= (p->next)->getval()){
				//cout<<p<<" "<<p->getval()<<endl;
				p=p->next;
				//cout<<"$ "<<p<<" "<<p->getval()<<endl;
			}
		}
		//cout<<"skipSearch ending"<<endl;
		return p;
	}

	void skipInsert(T el){
		node<T>* p = skipSearch(el);
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::minstd_rand0 a (seed); 
		if(p->getval() != el){
			//cout<<p<<endl;
			node<T>* new1 = new node<T>(el,p,p->next,NULL,NULL);
			(p->next)->prev = new1;
			p->next = new1;
			node<T>* eltoleftonhigher = p;
			node<T>* currentlayerel = new1;
			int i = 1;
			while(a()%2==1 && i<=max_height-1){
				eltoleftonhigher = currentlayerel->prev;
				while(eltoleftonhigher->above==NULL){
					eltoleftonhigher = eltoleftonhigher->prev;
				}
				eltoleftonhigher=eltoleftonhigher->above;
				node<T>* uplayercopy = new node<T>(el,eltoleftonhigher,eltoleftonhigher->next,NULL,new1);
				(eltoleftonhigher->next)->prev = uplayercopy;
				eltoleftonhigher->next = uplayercopy;
				currentlayerel->above = uplayercopy;
				currentlayerel = uplayercopy;
				i++;
			}
		}
	}

	void skipRemove(T el){
		node<T>* p = skipSearch(el);
		if(p->getval() == el){
			while(p->above!=NULL){
				(p->next)->prev = p->prev;
				(p->prev)->next = p->next;
				p=p->above;
			}
			(p->next)->prev = p->prev;
			(p->prev)->next = p->next;
		}
	}

	void ListIterate(){
		node<T>* curleft = topleftabove;
		node<T>* cur = curleft;
		for(int i=0;i<max_height+1;i++){
			cur = curleft;
			//cout<<"# "<<curleft<<" "<<cur<<" "<<(curleft->below)<<endl;
			while(cur->next!=NULL){
				cout<<cur->getval()<<" ";
				cur=cur->next;
			}
			cout<<cur->getval()<<" ";
			cout<<endl;
			curleft = curleft->below;
			if(curleft==NULL)
				break;
		}
	}
};

int main(){
	SkipList<int> sk(4);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::minstd_rand0 a (seed);
	for(int i=0;i<40000;i++){
		sk.skipInsert(a()%51239);
	}
	sk.skipInsert(4359);
	cout<<"\n\n";
	cout<<sk.skipSearch(4359)<<" "<<sk.skipSearch(4359)->getval()<<endl;


}


// Shubham Agarkar