#include "list.h"

void createList(List &L) {
    /**
    * FS : first(L) dan last(L) diset Nil
    */
    //-------------your code here-------------
    first(L) = NULL;
    last(L) = NULL;
    //----------------------------------------
}

address allocate(infotype x) {
    /**
    * FS : mengembalikan elemen list baru dengan info = x,
    *      next dan prev elemen = Nil
    */

    address P = NULL;
    //-------------your code here-------------
    P=new elmlist;
    info(P)=x;
    next(P)=NULL;
    prev(P)=NULL;
    //----------------------------------------
    return P;
}

void deallocate(address &P) {
    /**
    * FS : menghapus elemen yang ditunjuk oleh P (delete)
    */
    //-------------your code here-------------
    delete P;
    //----------------------------------------
}

void insertFirst(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen pertama pada List L
    */
    //-------------your code here-------------
    if (first(L)==NULL) {
        first(L)=P;
        last(L)=P;
        next(P)=first(L);
        prev(P)=first(L);
    } else {
        next(P)=first(L);
        prev(P)=last(L);
        next(last(L))=P;
        first(L)=P;
    }
    //----------------------------------------
}

void insertLast(List &L, address P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen yang ditunjuk P menjadi elemen terakhir pada List L
    */
    //-------------your code here-------------
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = first(L);
        prev(P) = last(L);
    }
    else {
        next(P) = first(L);
        prev(P) = last(L);
        prev(first(L)) = P;
        next(last(L)) = P;
        last(L) = P;
    }
    //----------------------------------------
}

address findElmByID(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.ID = x.ID,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
     if(first(L) != NULL){
        P = first(L);
        do{
            if(info(P).ID == x.ID){
                return P;
            }
            else{
                P = next(P);
            }
        }while(P!=first(L));
    }
    P = NULL;
    //----------------------------------------
    return P;
}

address findElmByName(List L, infotype x) {
    /**
    * IS : List L mungkin kosong
    * FS : mengembalikan elemen dengan info.name = x.name,
           mengembalikan Nil jika tidak ditemukan
    */

    address P = NULL;
    //-------------your code here-------------
    if(first(L) != NULL){
        P = first(L);
        do{
            if(info(P).name == x.name){
                return P;
            }
            else{
                P = next(P);
            }
        }while(P!=first(L));
    }
    P = NULL;
    //----------------------------------------
    return P;
}

void deleteFirst(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen pertama di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if (first(L) != NULL) {
        if (next(first(L)) == first(L)) {
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
            next(P) = NULL;
            prev(P) = NULL;
        }
        else {
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = last(L);
            next(last(L)) = first(L);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
    //----------------------------------------
}

void deleteLast(List &L, address &P) {
    /**
    * IS : List L mungkin kosong
    * FS : elemen tarakhir di dalam List L dilepas dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    if(first(L) != NULL){
        if(first(L) == last(L)){
            deleteFirst(L,P);
        }
        else{
            P = last(L);
            next(prev(P)) = first(L);
            prev(first(L)) = prev(P);
            last(L) = prev(P);
        }
    }
    //----------------------------------------
}

void insertAfter(List &L, address &Prec, address P) {
    /**
    * IS : Prec dan P tidak NULL
    * FS : elemen yang ditunjuk P menjadi elemen di belakang elemen yang
    *      ditunjuk pointer Prec
    */
    //-------------your code here-------------
    if (Prec!=NULL) {
        next(P)=next(Prec);
        prev(P)=Prec;
        prev(next(Prec))=P;
        next(Prec)=P;
    }
    //----------------------------------------

}
void deleteAfter(List &L, address &Prec, address &P) {
    /**
    * IS : Prec tidak NULL
    * FS : elemen yang berada di belakang elemen Prec dilepas
    *      dan disimpan/ditunjuk oleh P
    */
    //-------------your code here-------------
    P=next(Prec);
        next(Prec)=next(P);
        prev(next(P))=Prec;
        next(P)=NULL;
        prev(P)=NULL;
    //----------------------------------------
}

