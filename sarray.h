#ifndef SARRAY_H
#define SARRAY_H

#include <stdio.h>
#include "boolean.h"

#define MAX_ELM 10+1
#define Nil 0
typedef struct tStr_Node{
	int info;
	int next;
}Str_Node;

typedef struct tSt_ElmnList{
	int First;
	int Last;
	Str_Node Node[MAX_ELM];
}St_ElmnList;

boolean IsEmpty(int Next);
void Initial_Next(struct tSt_ElmnList& Linked);

void Insert_Akhir(struct tSt_ElmnList& Linked, int value);
void Insert_Awal(struct tSt_ElmnList& Linked, int value);

void Delete_Akhir(struct tSt_ElmnList& Linked);
void Delete_Awal(struct tSt_ElmnList& Linked);
void Delete_After(struct tSt_ElmnList& Linked,int alamat);

void Tampil(struct tSt_ElmnList& Linked);
void Insert_After(struct tSt_ElmnList& Linked,int alamat,int value);
int search(struct tSt_ElmnList& Linked,int value);

int NbElmt (tSt_ElmnList Linked); 
int Min (tSt_ElmnList Linked); 
int Rerata (tSt_ElmnList Linked); 
void BalikList (tSt_ElmnList& Linked); 
 
#endif
