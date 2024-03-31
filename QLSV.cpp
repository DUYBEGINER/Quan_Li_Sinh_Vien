#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

//Data sinh vien
typedef struct SinhVien{
    string HoTen[50];
    string maSV[10];
    int diemToan;
    int diemVan;
    int diemAnh;
    int diemTB;
} SV;

typedef struct NodeSV{
    SV data;
    struct  NodeSV* next; 
} NodeSV;

typedef NodeSV* NodeSVPointer;

//Danh sach sinh vien
typedef struct LinkedList
{
	NodeSVPointer head;
	NodeSVPointer tail;
}danhsachSV;

//khoi tao danh sach sinh vien
void  create_danhsach(danhsachSV &ds){
    ds.head = NULL;
    ds.tail = NULL;
}
//Khoi tao danh sach
void Init(NodeSVPointer  &head){
    head = new NodeSV;
}

//Nhap sinh vien
void NhapSv(NodeSVPointer &head){
    
    cout<<"Nhap Ho va Ten : ";      getline(cin,*head->data.HoTen);
    cout<<"Nhap Ma Sinh Vien: ";    getline(cin,*head->data.maSV);
    cout<<"Nhap diem Toan: ";       cin>>head->data.diemToan;
    cout<<"Nhap diem Van: ";        cin>>head->data.diemVan;
    cout<<"Nhap Diem Anh: ";       cin>>head->data.diemAnh;
    head->next = NULL;
    cin.ignore();
    
}

NodeSVPointer Search_SV(danhsachSV ds, string id){
    NodeSVPointer  p = ds.head;
    while (p!=NULL) {
        if (*p->data.maSV == id ) return p ;
        p = p -> next;
    }
    return NULL;
}


//Them sinh vien vao danh sach
void Them_SV(danhsachSV &ds){
    NodeSVPointer p;
    Init(p);
    NhapSv(p);
    if(ds.head==NULL){
        ds.head = p;
        ds.tail = p;
    }else{
        ds.tail->next =  p;
        ds.tail = p;
    }
}

//Show thong tin sinh vien
void Show_Sinhvien(NodeSVPointer sv){
    if(sv == NULL){
        cout<<"Khong ton tai  thong tin sinh vien nay!";
    }else{
        cout<<*sv->data.maSV<<'\t';
        cout<<*sv->data.HoTen<<'\t';
        cout<<sv->data.diemToan<<'\t';
        cout<<sv->data.diemVan<<'\t';
        cout<<sv->data.diemAnh<<'\t';
    }
}

//Show danh sach sinh vien
void Show_DanhSach(danhsachSV  ds) {
    if(ds.head == NULL) {
        cout << "Danh Sach Rong!" <<endl;
        return;
    }
    NodeSVPointer p = ds.head;
    while(p != NULL) {
        cout<<*p->data.maSV<<"\t";
        cout<<*p->data.HoTen<<"\t";
        cout<<p->data.diemToan<<"\t";
        cout<<p->data.diemVan<<"\t";
        cout<<p->data.diemAnh<<endl;
        p=p->next;
    }
}
int main(){
    //Khoi tao danh sach
    danhsachSV sinhvien;
    create_danhsach(sinhvien);
    Them_SV(sinhvien);
    Them_SV(sinhvien);
    Show_DanhSach(sinhvien);
    string id;
    cout<<"Nhap id muon tim: ";
    getline(cin,id);
    Show_Sinhvien(Search_SV(sinhvien,id));

    return 0;
}