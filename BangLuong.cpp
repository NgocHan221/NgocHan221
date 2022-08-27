#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

/** Cau Truc NhanVien **/
typedef struct 
{
	int maNV;
	char* hoTen;
	int luong;
} NhanVien;

/** Cau truc cua mot Node cho list kieu NhanVien **/
typedef struct Node 
{
	NhanVien Info;		 // Info: Chua thong tin cua Nhan Vien
	Node* pNext;	 	// pNext: Con tro tro toi Node ke tiep
} Node;

/** Cau truc dinh nghia mot Danh sach lien ket kieu NVNode **/
typedef struct 
{
	Node* pHead;  	 // Con tro chi Node dau tien cua list
	Node* pTail; 	// Con tro chi Node cuoi cung cua list
} LinkedList;

//====================================================================================================//

/** ============================= Cac phuong thuc tren DSLK ========================================== **/

/** Tao mot NhanVien moi voi 3 tham so **/
NhanVien CreateNhanVien(int ms, char* hoten, int luong)
{
	NhanVien nv;	
	nv.maNV = ms;
	nv.hoTen = hoten;
	nv.luong = luong;		
	return nv;
}

//====================================================================================================//

/** Tao mot Node moi, voi thong tin la NhanVien (info) **/
Node* CreateNode(NhanVien info) 
{
	Node* node = new Node;	// Cap phat vung nho cho Node	
	node->Info = info;		// Gan thong tin cho Node
	node->pNext = NULL;		// Cho duoi cua node chi ve NULL	
	return node;
}

//====================================================================================================//

/** In node moi **/
void PrintNode(Node* p)
{
	printf("%5d %30s %10d\n", p->Info.maNV, p->Info.hoTen, p->Info.luong );
}

//====================================================================================================//

/** Tao mot DSLK moi **/
void CreateList(LinkedList& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

//====================================================================================================//

/** Nhap node moi tu ban phim **/
Node* EnterNewNode()
{
	printf("Nhap Nhan vien moi\n");
	int ma, l;	
	char* ht; // Bien con tro kieu char de chua ten NhanVien
	ht = (char*)malloc(30* sizeof(char)); // Cap phat vung nho cho bien con tro	
	printf("Ma so: "); 
	scanf("%d", &ma);	
	printf("Ho ten: "); 
	fflush(stdin); 
	gets(ht);	
	printf("Luong: "); 
	scanf("%d", &l);
	NhanVien n = CreateNhanVien(ma,ht,l);	
	return CreateNode(n);		
}

//====================================================================================================//

/** 1. In danh sach tu dau **/
void PrintList(LinkedList &l)
{
	if (l.pHead ==NULL)
		printf("Danh sach rong\n");
	else
	{
		Node *p;
		p = l.pHead ;
		while (p!=NULL)
		{
			printf("%5d %30s %10d\n", p->Info.maNV, p->Info.hoTen, p->Info.luong );
			p = p->pNext;
		}		
	}
}

//====================================================================================================//

/*******===================Them mot Node new_ele vao DSLK l ==================================********/

/** 2. Them phan tu dau danh sach **/
void AddFirst(LinkedList& l, Node* new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

//====================================================================================================//

/** 3. Them phan tu cuoi danh sach **/
void AddLast(LinkedList &l, Node *new_ele)
{
	if (l.pHead==NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}
}

//====================================================================================================//

/** 4. Tim phan tu theo ten chinh xac **/
Node* SearchByExactName(LinkedList l, char* searchKey)
{	
	Node *p = l.pHead;
	while ((p!=NULL)&&(strcmp(searchKey, p->Info.hoTen)))
		p=p->pNext;
	return p;
}

//====================================================================================================//

/** 5. Tim phan tu theo tu khoa trong ten **/
LinkedList SearchByName(LinkedList l, char* searchKey)
{
	Node *p = l.pHead;
	char* found = NULL;
	
	LinkedList resultList ;
	CreateList(resultList);
	
	while ((p!=NULL))
	{
		found = strstr(p->Info.hoTen, searchKey); // Strstr: ham tim chuoi con trong chuoi me
		if (found)
		{		
			Node* newP = CreateNode(p->Info); // Tao node moi voi Info cua p ; Luu y khong duoc su dung p truc tiep			
			AddFirst(resultList, newP);
			printf("Found\n");
		}
		p=p->pNext;
	}
	return resultList;
}
//====================================================================================================//

/** 6. Tim theo ma nhan vien **/

Node* SearchByMaNV(LinkedList l, int ma)
{
	Node *p = l.pHead;
	while ((p!=NULL) && (p->Info.maNV != ma ) )
		p = p->pNext;
	return p;
}

//====================================================================================================//

/** 7. Tim phan tu co luong thap hon N (nhap tu ban phim) **/
LinkedList SearchLuongTHN(LinkedList l, int luongmoi)
{
	Node *p = l.pHead;
	int found = NULL;	
	LinkedList resultList ;
	CreateList(resultList);	
	while ((p!=NULL))
	{
		found = p->Info.luong<luongmoi; 
		if (found)
		{		
			Node* newP = CreateNode(p->Info);			
			AddFirst(resultList, newP);
			printf("Found\n");
		}
		p=p->pNext;
	}
	return resultList;
}

//====================================================================================================//

/** 8. Tim phan tu co luong cao hon N (nhap tu ban phim) **/
LinkedList SearchLuongCHN(LinkedList l, int luongmoi)
{
	Node *p = l.pHead;
	int found = NULL;	
	LinkedList resultList ;
	CreateList(resultList);	
	while ((p!=NULL))
	{
		found = p->Info.luong>luongmoi; 
		if (found)
		{		
			Node* newP = CreateNode(p->Info);			
			AddFirst(resultList, newP);
			printf("Found\n");
		}
		p=p->pNext;
	}
	return resultList;
}

//====================================================================================================//

/** 9. Them phan tu sau nut vua tim (sau khi tim bang 4 hoac 6) **/
void AddAfter(LinkedList &l, Node* q, Node* new_ele)
{
	if(q!=NULL)
	{
		new_ele->pNext = q->pNext;
		q->pNext = new_ele;
		if(q==l.pTail)
			l.pTail = new_ele;
	}
	else
	{
		AddFirst(l, new_ele);
	}
}

//====================================================================================================//

/** 10. Xoa phan tu dau danh sach **/
void RemoveHead(LinkedList &l)
{
	Node* p;
	if (l.pHead!=NULL)
	{
		p=l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
		if(l.pHead==NULL)
			l.pTail=NULL;
	}
}

//====================================================================================================//

/** 11. Xoa phan tu cuoi danh sach **/
void RemoveLast(LinkedList &l)
{
	Node* p;
	if(l.pHead==NULL)
		l.pTail=NULL;
	for(Node *p=l.pHead; p!=NULL; p=p->pNext)
	{
		if(p->pNext==l.pTail)
		{
			delete l.pTail; //Xoa phan tu cuoi 
			p->pNext=NULL; // Cho con tro cua node ke cuoi tro den vung nho null
			l.pTail=p; // Cap nhat lai l.pTail					
		}	
	}
}

//====================================================================================================//

/** 12. Xoa phan tu theo ten chinh xac **/
void RemoveByExactName(LinkedList &l, char* ten) 
{
    //tao node p de luu tru phan tu truoc node k can xoa
    Node *p, *q;
    //neu data dau vao bang voi pHead->data thi xoa dau
    if(strcmp(l.pHead->Info.hoTen, ten)==0){	
        //goi ham xoa dau
        RemoveHead(l);
        //ket thuc ham
        return;
    }
    //neu data bang voi pTail->data thi xoa cuoi
    if(strcmp(l.pTail->Info.hoTen, ten)==0){
        //goi ham xoa cuoi
        RemoveLast(l);
        //ket thuc ham
        return;
    }
    //duyet qua cac phan tu co trong danh sach
    for(q = l.pHead; q != NULL; q=q->pNext){
        //neu tim thay data trung voi k->data dang duyet
        if(strcmp(q->Info.hoTen, ten)==0){
            //gan con tro next cua node p bang con tro next cua node k
            p->pNext = q->pNext;
            //xoa di node k
            delete q;
            //ket thuc ham
            return;
        }
        //gan node p bang node k de node p luon la node dung truoc node k
        p = q;
    }
}

//====================================================================================================//

int main()
{
	char* ht[] ={"Nguyen Van An", "Tran Thuy Ai", "Le Phuoc Loc", "Tran Thi Kim Ha", "Van Ngoc Tuong"};
	int ma[N] = {1,2,3,4,5};
	int l[N] = {1000, 1500, 2200, 1800, 1300};
	
	LinkedList myNhanViens;	 //Khai bao list
	CreateList(myNhanViens); //Khoi tao list
	NhanVien nvs;
	
	for (int i = 0; i <N ; i++)
	{
		nvs = CreateNhanVien(ma[i], ht[i], l[i]);
		Node* new_ele; //Khai bao node	
		new_ele = CreateNode(nvs);
		AddFirst(myNhanViens, new_ele); // Dua node vao dau list	
	}	
	PrintList(myNhanViens);
	
	Node *new_ele, *p;
	LinkedList resultList;
	int key = 1;
	char q[30];
	int mact; 
	int luongmoi; 
	while (key)
	{
		printf("\n\n===============MENU=================\n");
		printf("0. Thoat\n");
		printf("1. In danh sach\n");
		printf("2. Them phan tu dau danh sach\n");
		printf("3. Them phan tu cuoi danh sach\n");
		printf("4. Tim phan theo ten chinh xac\n");
		printf("5. Tim phan tu theo tu khoa trong ten\n");
		printf("6. Tim phan tu theo ma nhan vien\n");
		printf("7. Tim phan tu co luong thap hon N (nhap tu ban phim)\n");
		printf("8. Tim phan tu co luong cao hon N (nhap tu ban phim)\n");		
		printf("9. Them phan tu sau nut vua tim (sau khi tim bang 4 hoac 6)\n");				
		printf("10. Xoa phan tu dau danh sach\n");
		printf("11. Xoa phan tu cuoi danh sach\n");
		printf("12. Xoa phan tu theo ten chinh xac");		
		printf("\n=====================================\n\n");	
		printf("--- Vui long chon thao tac ");
		scanf("%d",&key); 
		printf("--- Ban lua chon %d\n", key);
		switch (key)
		{
			case 0:				
				break;
				
			case 1:
				printf("======== In danh sach ========\n");
				PrintList(myNhanViens);
				break;
				
			case 2:
				printf("------> Nhap phan tu moi va them vao dau danh sach\n");								
				new_ele  = EnterNewNode();				
				AddFirst(myNhanViens, new_ele);				
				printf("\n \n *=*=*=*=*=*= Danh sach sau khi them phan tu *=*=*=*=*=*=*\n");
				PrintList(myNhanViens);
				break;
				
			case 3:
				printf("------> Nhap phan tu moi va them vao cuoi danh sach---\n");								
				new_ele  = EnterNewNode();				
				AddLast(myNhanViens, new_ele);				
				printf("\n \n *=*=*=*=*=*= Danh sach sau khi them phan tu *=*=*=*=*=*=\n");
				PrintList(myNhanViens);
				break;
				
			case 4:
				printf("-------> Tim phan tu theo ten\n")	;
				printf("--------> Nhap ten nhan vien can tim kiem: ");
				fflush(stdin);
				gets(q);				
				p = SearchByExactName(myNhanViens, q);
				if (p!=NULL)
					PrintNode(p);
				else
					printf("----- Khong tim thay nhan vien co ten: %s ------ \n", q);
				break;	
							
			case 5:				
				printf("-------> Tim theo tu khoa trong ten\n");				
				printf("------> Nhap ten nhan vien can tim kiem: ");
				fflush(stdin);
				gets(q);					
				resultList = SearchByName(myNhanViens, q);
				if (resultList.pHead!=NULL)					
					PrintList(resultList);
				else
					printf("----- Khong tim thay nhan vien co tu khoa %s trong ten -----\n", q);					
				break;						
			
			case 6:
				printf("------> Tim phan tu theo ma nhan vien\n")	;
				printf("=------> Nhap ma nhan vien can tim kiem: ");
				scanf("%d", &mact);				
				p = SearchByMaNV(myNhanViens, mact);
				if (p!=NULL)
					PrintNode(p);
				else
					printf("------ Khong tim thay nhan vien co ma: %d ------\n", ma);
				break;		
				
			case 7:	
				printf("------> Tim phan tu co luong thap hon N \n");				
				printf("-------> Nhap tien luong can so sanh: ");
				scanf("%d", &luongmoi);				
				resultList = SearchLuongTHN(myNhanViens, luongmoi);
				if (resultList.pHead!=NULL)					
					PrintList(resultList);
				else
					printf("------ Khong tim thay nhan vien co luong thap hon: %d ------\n", luongmoi);					
				break;	
				
			case 8:
				printf("-------> Tim phan tu co luong cao hon N \n");				
				printf("--------> Nhap tien luong can so sanh: ");
				scanf("%d", &luongmoi);				
				resultList = SearchLuongCHN(myNhanViens, luongmoi);
				if (resultList.pHead!=NULL)					
					PrintList(resultList);
				else
					printf("------ Khong tim thay nhan vien co luong cao hon: %d ------\n", luongmoi);					
				break;
			
			
			case 9:	
				printf("-----> Tim phan tu theo ten\n")	;
				printf("-------> Nhap ten nhan vien can tim kiem: ");
				fflush(stdin);
				gets(q);				
				p = SearchByExactName(myNhanViens, q);
				printf("-------> Nhap phan tu moi va them vao node vua tim---\n");								
				new_ele  = EnterNewNode();					
				AddAfter(myNhanViens, p, new_ele);				
				printf("\n \n ======== Danh sach sau khi them phan tu moi ========\n");
				PrintList(myNhanViens);
				break;	
			
			case 10:
				printf("------> Xoa phan tu dau danh sach\n");	
				RemoveHead(myNhanViens);											
				printf("\n \n ======== Danh sach sau khi da xoa phan tu dau danh sach ========\n");
				PrintList(myNhanViens);
				break; 
				
			case 11:
				printf("===>> Xoa phan tu cuoi danh sach\n");	
				RemoveLast(myNhanViens);											
				printf("\n \n ======== Danh sach sau khi da xoa phan tu cuoi danh sach ========\n");
				PrintList(myNhanViens);
				break;
					
			case 12:
				printf("-------> Xoa phan tu theo ten chinh xac\n");	
				printf("===>> Nhap ten nhan vien can xoa: ");	 
				fflush(stdin); 
				gets(q);
				RemoveByExactName(myNhanViens, q);											
				printf("\n \n ======== Danh sach sau khi da xoa phan tu theo ten chinh xac ========\n");
				PrintList(myNhanViens);
				break;		
		
			default:
				printf("Chuc nang chua cai dat");
		}			
	}	
	return 0;	
}
