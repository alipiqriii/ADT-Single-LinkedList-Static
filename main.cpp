/*
ADT STATIK
Oleh 	: Ali Piqri Sopandi
Nim		: 171511035
*/

#include <stdio.h>
#include "sarray.h"
main(){
	int i;
	int alamat_cari;
	
	St_ElmnList Static_Linear;
	Static_Linear.First = Nil;
		Static_Linear.Last = Nil;
	//inisialisasi NULL
	Initial_Next(Static_Linear);
	
	//Create Node
	Insert_Akhir(Static_Linear,1000);
	Tampil(Static_Linear);
	
	Insert_Awal(Static_Linear,10);
	Tampil(Static_Linear);
	
	Insert_Awal(Static_Linear,20);
	Tampil(Static_Linear);
	
	Insert_Awal(Static_Linear,30);
	Tampil(Static_Linear);
	
	Insert_Awal(Static_Linear,40);
	Tampil(Static_Linear);
	
	Insert_Akhir(Static_Linear,2000);
	Tampil(Static_Linear);
	
	Delete_Awal(Static_Linear);
	Tampil(Static_Linear);
	
	Insert_Akhir(Static_Linear,3000);
	Tampil(Static_Linear);
	
	alamat_cari = search(Static_Linear,2000);
	Insert_After(Static_Linear,alamat_cari,99);
	Tampil(Static_Linear);
	
	alamat_cari = search(Static_Linear,2000);
	Delete_After(Static_Linear,alamat_cari);
	Tampil(Static_Linear);
	
	Insert_Awal(Static_Linear,999);
	Tampil(Static_Linear);
	
	Insert_Awal(Static_Linear,55);
	Tampil(Static_Linear);
	
	Insert_Akhir(Static_Linear,2);
	Tampil(Static_Linear);
	
	Insert_Akhir(Static_Linear,877);
	Tampil(Static_Linear);
	
	BalikList(Static_Linear);
	Tampil(Static_Linear);
	
	int min=Min(Static_Linear);
	printf("Min %d\n",min);
	
	int rerata=Rerata(Static_Linear);
	printf("Rerata %d\n",rerata);
	
	int Jum_Elemen=NbElmt(Static_Linear);
	printf("Jumlah Elemen %d\n",Jum_Elemen);

}
