#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;

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

typedef  NodeSV * NodeSVPointer;
NodeSVPointer head;

//Khoi tao danh sach
void Init(NodeSVPointer  &head){
    head = NULL;
}

//Nhap sinh vien
void NhapSv(NodeSVPointer &head){
    cout<<"Nhap Ho va Ten : ";      cin>>*head->data.HoTen;
    cout<<"Nhap Ma Sinh Vien: ";    cin>>*head->data.maSV;
    cout<<"Nhap diem Toan: ";       cin>>head->data.diemToan;
    cout<<"Nhap diem Van: ";        cin>>head->data.diemVan;
    cout<<"Nhap Diem Anh: ";       cin>>head->data.diemAnh;
    cout<<"\n";
}

//Tao node sinh vien
// NodeSVPointer CreateSV(SV value){
//     NodeSVPointer p = new NodeSV;
//     if(p==NULL){
//         cout<<"Khong the tao moi";
//         return NULL;
//     }
// }

void Show_DanhSach(NodeSVPointer head) {
    NodeSVPointer p = head;
    while(p != NULL) {
        cout<<*p->data.maSV;
        cout<<*p->data.HoTen;
        cout<<p->data.diemToan<<"\t";
        cout<<p->data.diemVan<<"\t";
        cout<<p->data.diemAnh<<endl;
        p=p->next;
    }
}
int main(){
    //Khoi tao danh sach
    NodeSV* sinhvien = new NodeSV;
    NhapSv(sinhvien);
    Show_DanhSach(sinhvien);
    return 0;

}