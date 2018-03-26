/*
ADT STATIK
Oleh 	: Ali Piqri Sopandi
Nim		: 171511035
*/

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "sarray.h"
main(){
	int hasil;
	infotype value,data;
	int c;
	int alamat_cari;
	
	St_ElmnList Static_Linear;
	Static_Linear.First = Nil;
	Static_Linear.Last = Nil;
	
	//inisialisasi NULL
	Initial_Next(&Static_Linear);
	
	//Create Node
	while(1){
		system("cls");
		printf("1. Insert Awal\n");
		printf("2. Insert Akhir\n");
		printf("3. Insert After\n");
		printf("4. Delete Awal\n");
		printf("5. Delete Akhir\n");
		printf("6. Delete After\n");
		printf("7. Rerata\n");
		printf("8. Min\n");
		printf("9. Jumlah Elemen\n");
		printf("10. Balik List\n");
		printf("11. Sort\n");
		printf("12. Tampil\n");
		printf("Pilihan :");scanf("%d",&c);
		switch(c){
			case 1: 
				printf("Value : ");scanf("%d",&value);
				Insert_Awal(&Static_Linear,value);
				break;
			case 2: 
				printf("Value : ");scanf("%d",&value);
				Insert_Akhir(&Static_Linear,value);
				break;
			case 3:
				printf("Data Yang Dicari : ");scanf("%d",&data);
				printf("Value : ");scanf("%d",&value);
				alamat_cari = search(Static_Linear,data);
				Insert_After(&Static_Linear,alamat_cari,value);
				break;
			case 4:
				Delete_Awal(&Static_Linear);
				break;
			case 5:
				Delete_Akhir(&Static_Linear);
				break;
			case 6:
				printf("Data Yang Dicari : ");scanf("%d",&data);
				alamat_cari = search(Static_Linear,data);
				Delete_After(&Static_Linear,alamat_cari);
				break;
			case 7:
				hasil=Rerata(Static_Linear);
				printf("Rata 2 : %d\n",hasil);
				break;
			case 8:
				hasil=Min(Static_Linear);
				printf("Min : %d\n",hasil);
				break;
			case 9:
				hasil=NbElmt(Static_Linear);
				printf("Jumlah Elemen %d\n",hasil);
				break;
			case 10:
				BalikList(&Static_Linear);
				break;
			case 11:
				Sort(&Static_Linear);
				break;
			case 12:
				Tampil(Static_Linear);
				system("pause");
		}
	}
}
