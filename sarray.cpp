#include "sarray.h"
#include "boolean.h"
#include "conio.h"

boolean IsEmpty(int Next){
	if(Next == Nil) return true;
	else return false;
}
boolean IsFull(tSt_ElmnList Linked){
	int Sum = NbElmt(Linked);
	if(Sum == MAX_ELM-1) return true;
	else return false;
	
}
void Initial_Next(struct tSt_ElmnList& Linked){
	int i;
	for(i=Linked.First;i<MAX_ELM;i++){
		Linked.Node[i].next = Linked.Node[i].info = Nil;
	}
}

void Insert_Awal(struct tSt_ElmnList& Linked, int value){
	int pos=1;
	boolean found=false;
	if(IsEmpty(Linked.First)){
		Linked.First = Linked.Last = 1;
		Linked.Node[Linked.First].next = Nil;        
   		Linked.Node[Linked.First].info = value;
	}
	else {
		if(!IsFull(Linked)){
			//Cari Posisi Untuk Penempatan
			while(!found){	
				while(!IsEmpty(Linked.Node[pos].next)) pos++;
				if (Linked.Last == pos) pos++;
				else found=true;
			}
			Linked.Node[pos].info = value;
			Linked.Node[pos].next = Linked.First;
			Linked.First = pos;
		}
	}
}

void Insert_Akhir(struct tSt_ElmnList& Linked, int value){
	int pos=1;
	boolean found=false;
	if(IsEmpty(Linked.Last)){
		Linked.First = Linked.Last = 1;
		Linked.Node[Linked.Last].next = Nil;        
   		Linked.Node[Linked.Last].info = value;
	}
	else {
		if(!IsFull(Linked)){
			//Cari Posisi Untuk Penempatan
			while(!found){	
				while(!IsEmpty(Linked.Node[pos].next)) pos++;
				if (Linked.Last == pos) pos++;
				else found=true;
			}
			Linked.Node[Linked.Last].next = pos;
			Linked.Node[pos].info = value;
			Linked.Node[pos].next = Nil;
			Linked.Last = pos;
		}
	}
}

void Insert_After(struct tSt_ElmnList& Linked,int alamat,int value){
	int pos=1;
	boolean found=false;
	if(!IsEmpty(alamat)){
		if(!IsFull(Linked)){
			//Cari Posisi Untuk Penempatan
			while(!found){	
				while(!IsEmpty(Linked.Node[pos].next)) pos++;
				if (Linked.Last == pos) pos++;
				else found=true;
			}
			Linked.Node[pos].info = value;
			Linked.Node[pos].next = Linked.Node[alamat].next;
			Linked.Node[alamat].next = pos;
		}
	}
}

void BalikList(struct tSt_ElmnList& Linked){
		int i,prev,next1,temp;
		i = Linked.First;
		prev = Nil;
		do{
			next1 = Linked.Node[i].next;
			Linked.Node[i].next = prev;
			prev = i;
			i = next1; 
			
		}while(Linked.Node[i].next!=Nil);
			
		Linked.Node[i].next = prev;
		temp = Linked.First;
		Linked.First = Linked.Last;
		Linked.Last = temp;
}
void Delete_Awal(struct tSt_ElmnList& Linked){
	int i=Linked.First;
	
	if(!IsEmpty(Linked.First)){
		Linked.First = Linked.Node[i].next;
		Linked.Node[i].next = Nil;
	}
}

void Delete_Akhir(struct tSt_ElmnList& Linked){
	int i=Linked.First;
	int before;
	if(!IsEmpty(Linked.First)){
		while(!IsEmpty(Linked.Node[i].next)){
			before=i;
			i=Linked.Node[i].next;
		}
		Linked.Node[before].next = Nil;
		Linked.Last = before;
	}
}

void Delete_After(struct tSt_ElmnList& Linked,int alamat){
	int i=Linked.Node[alamat].next;
	//boolean found=false;
	if(!IsEmpty(alamat)){
		Linked.Node[alamat].next = Linked.Node[i].next;
		Linked.Node[i].next = Nil;
	}	
}

int search(struct tSt_ElmnList& Linked,int value){
	int i=Linked.First;
	boolean found=false;
	
	if(!IsEmpty(Linked.First)){
		while(!IsEmpty(Linked.Node[i].next) && !found){
			if (Linked.Node[i].info == value) found=true;
			else i=Linked.Node[i].next;
		}
		if(found) return i;
		else return 0;
	}
}

void Tampil(struct tSt_ElmnList& Linked){
	int i=Linked.First;
	
	while(!IsEmpty(Linked.Node[i].next)){
		printf("%d ",Linked.Node[i].info);
		i=Linked.Node[i].next;
	}
	printf("%d ",Linked.Node[i].info);
	printf("\n");
}

int Min(struct tSt_ElmnList Linked){
	int min,i;
	if(!IsEmpty(Linked.First)){	
			i = Linked.First;
			min = Linked.Node[i].info;
			while(Linked.Node[i].next != Nil){
				i = Linked.Node[i].next;
				if(Linked.Node[i].info < min){
					min = Linked.Node[i].info;
				}
			}
			if(Linked.Node[i].info < min) min = Linked.Node[i].info;
			return min;
		}
	else return 0;
}

int Rerata(tSt_ElmnList Linked){
		if (!IsEmpty(Linked.First)){
			int Tot, Sum, Avg; 
			int i = Linked.First;
			Tot = Linked.Node[i].info;
			while(Linked.Node[i].next!=Nil){
				i = Linked.Node[i].next;
				Tot = Tot + Linked.Node[i].info;
			}
			Sum=NbElmt(Linked);
			Avg = Tot/Sum;
			return Avg;	
		}
		else return 0;
}

int NbElmt (tSt_ElmnList Linked){
		if (!IsEmpty(Linked.First)){
			int Sum = 1;
			int i = Linked.First;
			while(Linked.Node[i].next!=Nil){
				i = Linked.Node[i].next;
				Sum++;
			}
			return Sum;	
		}
}
