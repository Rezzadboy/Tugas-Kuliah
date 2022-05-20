#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#define jmlh 100
using namespace std;

struct Stack{
    int batas = 0, limit = 0, skor =0, n, cepat;
    int data[jmlh], angka[jmlh];
    string pilih;
    char jawab;

    void acak(){
        srand(time(0));
        for(int i = 1; i <= n; i++){
            limit++;
            angka[limit] = rand()% 100 + 1;
        }
    }

    void Push(){
        if(batas == jmlh){
            cout<<"Penuh\n";
        
        }else{
            batas++;
            cout<<"Masukkan Angka: ";
            cin>> data[batas];
        }
    }
    
    void Pop(){ 
        if(batas == 0){ 
            cout<<"Kosong!\n";
        
        }else{ 
            data[batas--];
        }
    }

    void cetak(){ 
        if(limit == 0){ 
            cout<<"===Data Stack====\n";
            cout<<"=Kosong=\n";
        
        }else{ 
            cout<<"===Data Stack===\n";
            for(int i = limit; i >= 1; i--){ 
                cout<<"===   ["<<angka[i]<<"]    ===" <<"\n";
            }
        }
    }

    void printf(){
        if(batas == 0){
            cout<<"===Jawaban===\n";
            cout<<"=Kosong=\n";
        
        }else{
            cout<<"===  Jawaban  ===\n";
            for(int i = batas; i >= 1; i--){ 
                cout<<"===   ["<<data[i]<<"]    ===" <<"\n";
            }
        }
    }

    void jawaban(){
        cout<<"===Data Stack===\t\t\t===  Jawaban  ===\n";
        for(int i = limit; i >= 1; i--){ 
            cout<<"===   ["<<angka[i]<<"]    ===\t\t\t" <<"===    [" <<data[i] << "]   ===\n";
        }
    }

    void cek(){
        for(int i = 1; i <= n; i++){
            if(angka[i] == data[i]){
                skor++;
            }
        }
        cout<<"Total Jawaban Benar: "<<skor <<"\n";

        if(skor == n){
            cout<<"Jawaban Benar Semua\n";
        
        }else{
            cout<<"Jawaban Anda salah\n";
        }

    }

    void loading(){
        for (int i = cepat; i >= 0; i--){
            cetak();
            cout<<"Sisa Waktu: " << i;
            Sleep(500);
            system("cls");
        }
    }

    int hapus(){
        return batas = 0;
    }

    int clear(){
        return limit = 0;
    }

    int bersih(){
        return skor = 0;
    }

};

int main(){
    Stack Tumpuk;
    Tumpuk.n = 1;

    do{
    Tumpuk.clear();
    Tumpuk.hapus();
    Tumpuk.bersih();
    
    cout<<"Level Permainan: " << Tumpuk.n;
    cout<<"\nMasukkan Kecepatan: ";
    cin>> Tumpuk.cepat;
    system("cls");

    Tumpuk.acak();
    Tumpuk.loading();

    do{
        Tumpuk.printf();
        cout<<"Masukkan Pilihan: ";
        cin>> Tumpuk.pilih;

        if(Tumpuk.pilih == "Push" || Tumpuk.pilih == "push"){
            Tumpuk.Push();
            system("cls");
        
        }else if(Tumpuk.pilih == "Pop" || Tumpuk.pilih == "pop"){
            Tumpuk.Pop();
            system("cls");

        }

    }while(Tumpuk.pilih != "cek" && Tumpuk.pilih != "Cek");
    system("cls");

    Tumpuk.jawaban();
    Tumpuk.cek();

    cout<<"Ingin Bermain lagi y/n?: ";
    cin>>Tumpuk.jawab;
    Tumpuk.n++;
    system("cls");
    }while(Tumpuk.jawab != 'n');
}
