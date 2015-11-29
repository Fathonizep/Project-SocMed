#include <iostream>
#include <stdlib.h>
#include "header.h"
#include <windows.h>

using namespace std;

int main()
{
    system("COLOR 9f");
    List_status l;
    status x;
    like y;
    adr_status p;
    adr_like q,r;
    createstatus(l);
    int pil;
    int cariID;
    while (pil!=11)
    {
        system("CLS");
        cout<<"                  |===========================================|"<<endl;
        cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
        cout<<"                  |          Making Everyone Connected        |"<<endl;
        cout<<"                  |===========================================|"<<endl;

        cout<< "                  |   1. Home                                 |"<<"\n"
            << "                  |   2. Add Status                           |"<<"\n"
            << "                  |   3. Find Status By ID                    |"<<"\n"
            << "                  |   4. Edit Status                          |"<<"\n"
            << "                  |   5. Add Like                             |"<<"\n"
            << "                  |   6. Find Like by ID                      |"<<"\n"
            << "                  |   7. Unlike                               |"<<"\n"
            << "                  |   8. View List Like from Status           |"<<"\n"
            << "                  |   9. Delete Status and Like               |"<<"\n"
            << "                  |  10. View Max Like                        |"<<"\n"
            << "                  |  11. Exit                                 |"<<"\n"
            << "                  |                                           |"<<"\n"
            << "                      Choose: ";
            cin >> pil;

        if (pil==2)
        {
            system("CLS");
            add_stat(x);
            adr_status r=findstat_sama(l,x.id_status);
            if(r==nil)
            {
                p=alokasi_status(x);
                insertfirst_stat(l,p);
                cout << endl <<"                      Your Status Has been Updated !" << endl;
                viewlist_stat(l);
            }

            getch();
        }
        else if (pil==1)
        {

            system("CLS");
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | View Status "<<endl;
            viewlist_stat(l);
            getch();


        }
        else if (pil==3)
        {
            system("CLS");
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | Input ID : ";
            cin >>cariID;
            p=findstat(l,cariID);
            cout<<"                                                              |"<<endl;
            cout<<"                  | Your Status                               |"<<endl;
            cout<<"                  |   ID Status    : "<<info_stat(p).id_status<<endl;
            cout<<"                  |   Status       : "<<info_stat(p).s<<endl;
            getch();
            system("CLS");
        }
        else if (pil==4)
        {
            system("CLS");
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | Data Of Status                            | " << endl;
            viewlist_stat(l);
            cout << endl;
            cout<<"                  |  Input ID Status which be changed : ";
            cin >> cariID;
            p=findstat(l,cariID);
            cout<<"                  |      Your Status : ";
            cin >> info_stat(p).s;
            cout<<"                  |       Has Been Updated !";

        }
        else if (pil==5)
        {
            system("CLS");
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | Data Of Status                            | " << endl;
            viewlist_stat(l);
            cout << endl;
            cout<<"                  |   Input ID Status Which be Liked : ";
            cin >> cariID;
            p=findstat(l,cariID);
            add_like(y,p);
            if(!checkLikedUser(p,y.id_user))
            {
                adr_like q=alokasi_like(y);
                insertlast_like(p,q);
                viewlist_like(p,q);
            }
            else
            {
                cout << "User sudah liked";
            }
            getch();
        }
        else if (pil==6)
        {
            system("CLS");
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | Find Like Of Status                       | " << endl;
            viewlist_like(p,q);
            cout << endl;
            cout<<"                     Masukkan ID Status untuk mencari Data like : ";
            cin >> cariID;
            p=findstat(l,cariID);
            {
   cout << endl <<"                     Masukkan ID like yang Anda cari : " ;
                cin >> cariID;
                q = findlike(p,cariID);
            cout<<"                     Data like sebagai berikut : \n" << endl;
            cout<<"                     ID Status : "<<info_like(q).id_like<<endl;


            }
            getch();
        }
        else if (pil==7)
        {
            system("CLS");
            cout << "Input ID Status for Unlike status: ";
            cin >> cariID;
            p=findstat(l,cariID);
            if(p!=nil)
            {
                int h;
                viewlist_like(p,q);
                cout << "Masukkan ID like yang ingin dihapus: ";
                cin >> h;
                adr_like hapus=findlike(p,h);
                if(hapus!=nil)
                {
                    deleteafter_like(p,q,h);
                    viewlist_like(p,q);
                }
            }
            else
            {
                cout <<"ID status belum di input";
            }

            getch();
        }
        else if (pil==8)
        {
            system("CLS");
            viewlist_stat(l);
            cout << "Masukkan ID Status untuk menampilkan Data like : ";
            cin >> cariID;
            p=findstat(l,cariID);
            if(p!=nil)
            {
                system("CLS");
                viewlist_like(p,q);
            }
            else
            {
                cout <<"ID Status belum di input";
            }
            getch();
        }
        else if (pil==9)
        {
            system("CLS");
            adr_status prec;
            system("CLS");
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | Delete Status with Like                   | " << endl;
            viewlist_stat(l);
            cout<<"                  |                                           | "<<endl;
            cout<<"                     Input ID Status yang ingin anda hapus: ";
            cin >> cariID;
            p=findstat(l,cariID);
            if (p!=nil)
            {
                deleteafter_stat(l,p,prec);
                viewlist_stat(l);
            }
            getch();
        }

        else if (pil==10)
        {
            system("CLS");
            getmaxlike(l);
            getch();
        }


    }

    return 0;
}
