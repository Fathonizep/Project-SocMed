#include <iostream>
#include "header.h"

using namespace std;

void createstatus (List_status &l)
{
    first(l)=nil;
    last(l)=nil;
}

adr_status alokasi_status (status x)
{
    adr_status p=new elmstatus;
    info_stat (p)=x;
    next(p)=nil;
    prev(p)=nil;
    firstlike(p)=nil;
    liked(p)=0;
    return p;
}
adr_like alokasi_like (like y)
{
    adr_like p=new elmlike;
    info_like(p)=y;
    next(p)=nil;
    return p;
}

//Insert First
void insertfirst_stat (List_status &l, adr_status p)
{
    if (first(l)==nil)
    {
        first(l)=p;
        last(l)=p;
    }
    else
    {
        next(p)=first(l);
        prev(first(l))=p;
        first(l)=p;

    }
}
void insertfirst_like (adr_status &p, adr_like &q)
{
    if (firstlike(p)==nil)
    {
        firstlike(p)=q;
    }
    else
    {
        next(q)=firstlike(p);
        prev(firstlike(p))=q;
        firstlike(p)=q;


    }
}

//Insert Last
void insertlast_stat (List_status &l, adr_status p)
{
    if(first(l)==nil)
    {
        first(l)=p;
        last(l)=p;
    }
    else
    {
        prev(p)=last(l);
        next(last(l))=p;
        last(l)=p;
    }
}
void insertafter_stat (List_status &l, adr_status p, adr_status prec)
{
    if (next(prec) == last(l))
    {
        insertlast_stat(l,p);
    }
    else
    {
        next(p)=next(prec);
        prev(p)=prec;
        prev(next(prec))=p;
        next(prec)=p;
    }
}
void insertlast_like (adr_status &p, adr_like &q)
{
    int newlike;
    adr_like r=firstlike(p);
    if (firstlike(p)==nil)
    {
        info_like(q).id_like=1;
        firstlike(p)=q;
        lastlike(p)=q;
    }
    else
    {
        info_like(q).id_like=info_like(lastlike(p)).id_like + 1;
        next((lastlike(p)))=q;
        prev(q)=lastlike(p);
        lastlike(p)=q;
    }
    liked(p)++;
}

//DELETE LAST
void deletefirst_stat (List_status &l, adr_status &p)
{
    if (first(l)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(l)==last(l))
    {
        first(l)=nil;
        last(l)=nil;
    }
    else
    {
        p=first(l);
        first(l)=next(first(l));
        next(p)=nil;
        prev(first(l))=nil;
    }
}
void deletefirst_like (adr_status &p, adr_like &q)
{
    if (firstlike(p)!=nil)
    {
        q=firstlike(p);
        if (next(q)!=nil)
        {
            firstlike(p)=next(firstlike(p));
            next(q)=nil;
            prev(firstlike(p))=nil;
        }
        else
        {
            firstlike(p)=nil;
        }
    }
}

void deleteafter_like (adr_status &p, adr_like &q,int y)
{
    if (firstlike(p)!=nil)
    {
        q=firstlike(p);
        while (info_like(q).id_like!=y)
        {
            q=next(q);
        }
        adr_like prec=prev(q);

        if(next(q)==nil && prev(q)==nil){
            firstlike(p)=nil;
            lastlike(p)=nil;
        }
        else{
            if(prev(q)==nil){
                firstlike(p)=next(q);
                prev(next(q))=nil;
            }
            else if(next(q)==nil){
                lastlike(p)=prev(q);
                next(prev(q))=nil;
            }
            else{
                prev(next(q))=prev(q);
                next(prev(q))=next(q);
            }
        }
        liked(p)--;
    }
}
void deleteafter_stat (List_status &l,adr_status &p, adr_status prec)
{
    if(p==first(l))
    {
        deletefirst_stat(l,p);
    }
    else if(p==last(l))
    {
        deletelast_stat(l,p);
    }
    else
    {
        prec=prev(p);
        next(prec)=next(p);
        prev(next(p))=prec;
        prev(p)=nil;
        next(p)=nil;
    }
}

//DELETE LAST
void deletelast_stat (List_status &l, adr_status &p)
{
    if (first(l)==nil)
    {
        cout << "data tidak ada";
    }
    else if(first(l)==last(l))
    {
        first(l)=nil;
        last(l)=nil;
    }
    else
    {
        p=last(l);
        last(l)=prev(last(l));
        prev(p)=nil;
        next(last(l))=nil;
    }
}
void deletelast_like (adr_status &p, adr_like &q)
{
    q=lastlike(p);
    if(q!=nil)
    {
        lastlike(p)=prev(q);
        prev(q)=nil;
        next(lastlike(p))=nil;
    }
    else
    {
        cout << "data tidak ada";
    }
}

adr_status findstat (List_status l,int x)
{
    adr_status p;
    p=first(l);
    while(p!=nil && info_stat(p).id_status!=x)
    {
        p=next(p);
    }

    if(p!=nil)
    {
        return p;
    };

    return nil;
}

adr_status findstat_sama (List_status l,int x)
{
    adr_status p;
    p=first(l);
    while(p!=nil)
    {
        if (info_stat(p).id_status==x)
        {
            return p;
        }
        else
        {
            p=next(p);
        }
    }

}
adr_like findlike (adr_status p,int y)
{
    adr_like q;
    q=firstlike(p);
    while(q!=nil && info_like(q).id_like!=y)
    {
        q=next(q);
    }
    if(q!=nil)
    {
        return q;
    }
    return nil;
}
adr_like findlike_sama (adr_status p,int y)
{
    adr_like q;
    q=firstlike(p);
    while(q!=nil)
    {
        if(info_like(q).id_like==y)
        {
            return q;
        }
        else
        {
            q=next(q);
        }
    }
}

void viewlist_stat (List_status l)
{
    adr_status p;
    adr_like q;
    p=first(l);
    while (p!=nil)
    {
            cout <<"                   "<<endl
                 <<"                        ["<<info_stat(p).id_status<<"]"<<". Your Status : "<<info_stat(p).s<<endl
                 <<"                             Liked       : "<<liked(p)<<endl;
        p=next(p);
    }
}
void viewlist_like (adr_status &p,adr_like q)
{
    if (firstlike(p)!=nil)
    {
        q=firstlike(p);
        while(q!=nil)
        {
            cout <<"                    ID like : "<< info_like(q).id_like<<endl;
            cout <<"                    ID user : "<< info_like(q).id_user<<endl;
            q=next(q);
        }
    }
}

void add_stat(status &x)
{
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | Write Status                              |\n"<<endl;
            cout<<"                  |   ID Status : ";
            cin >> x.id_status;
            cout<<"                  |   Create your Status : ";
            cin >> x.s;
}
void add_like(like &y,adr_status &p)
{
            cout<<"\n";
            cout<<"                        ID User : ";
            cin >> y.id_user;

}


void getmaxlike(List_status l){
    adr_status p=first(l);
    adr_status mostliked=p;
    while(p!=nil)
    {

        if(liked(p)>liked(mostliked))
        {
            mostliked=p;
        }
        p=next(p);
    }
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  |             FACENOTE SOCIAL MEDIA         |"<<endl;
            cout<<"                  |          Making Everyonne Connected       |"<<endl;
            cout<<"                  |===========================================|"<<endl;
            cout<<"                  | Most Liked                                |\n"<<endl;
            cout<<"                      ["<<info_stat(mostliked).id_status<<"]"<<". Status : "<<info_stat(mostliked).s<<endl;
            cout<<"                  |         Liked : "<<liked(mostliked);
}

bool checkLikedUser(adr_status stat,int id_user){
    adr_like p=firstlike(stat);
    while(p!=nil){
        if(info_like(p).id_user==id_user)
            return true;

        p=next(p);
    }
    return false;
}
