#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <string>

#define info_stat(p) (p)->info_stat
#define info_like(p) (p)->info_like
#define next(p) (p)->next
#define next_like(p) (p)->next_like
#define prev(p) (p)->prev
#define first(l) ((l).first)
#define last(l) ((l).last)
#define firststat(p) (p)->firststat
#define liked(p) (p)->liked
#define laststat(p) (p)->laststat
#define firstlike(p) (p)->firstlike
#define lastlike(p) (p)->lastlike
#define nil NULL

using namespace std;

typedef struct elmstatus *adr_status;
typedef struct elmuser *adr_user;
typedef struct elmlike *adr_like;

struct status
{
    int id_status;
    string s;
};

struct elmstatus
{
    status info_stat;
    adr_status next,prev;
    adr_user user;
    int liked;
    adr_like firstlike,lastlike;
};

struct like
{
    int id_like;
    int id_user;
};

struct elmlike
{
    like info_like;
    adr_like next,prev;
};

struct List_status
{
    adr_status first,last;
};

void createstatus (List_status & );

adr_status alokasi_status (status );
adr_like alokasi_like (like );

void insertfirst_stat (List_status &, adr_status );
void insertfirst_like (adr_status &, adr_like &);

void insertafter_stat (List_status &, adr_status, adr_status );

void insertlast_stat (List_status &, adr_status );
void insertlast_like (adr_status &, adr_like &);

void deletefirst_stat (List_status &, adr_status &);
void deletefirst_like (adr_status &, adr_like &);

void deleteafter_stat (List_status &,adr_status &,adr_status );
void deleteafter_like (adr_status &, adr_like &,int );

void deletelast_stat (List_status &, adr_status &);
void deletelast_like (adr_status &, adr_like &);

adr_status findstat (List_status ,int );
adr_like findlike (adr_status ,int );

void viewlist_stat (List_status );
void viewlist_like (adr_status &,adr_like );

void add_stat(status &);
void add_like(like & ,adr_status & );

adr_status findstat_sama (List_status ,int );
adr_like findlike_sama (adr_status ,int );

//ADDITIONAL FUNCT
void getmaxlike(List_status l);
bool checkLikedUser(adr_status stat,int id_user);

#endif // LIST_H_INCLUDED
