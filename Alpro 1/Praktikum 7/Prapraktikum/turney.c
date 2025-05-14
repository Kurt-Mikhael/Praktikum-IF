

#define CAPACITY 100
#define IDX_UNDEF -1

typedef int ElType;

typedef struct {
    ElType contents[CAPACITY]; // elemen disimpan kontigu
    int nEff;                  // jumlah elemen efektif
} List;

/* Membuat list kosong (CreateList)
 * I.S. : List l belum diinisialisasi
 * F.S. : List l kosong 
 */
void CreateList(List *l){
    l->nEff = 0;
    for (int i = 0; i < CAPACITY; i++) {
        l->contents[i] = IDX_UNDEF;
    }
}

/* Mengembalikan jumlah elemen efektif list
 * I.S. : List l terdefinisi
 * F.S. : Jumlah elemen efektif
 */
int length(List l){
    return l.nEff;
}

/* Mengambil elemen ke-i dari list
 * I.S. : List l terdefinisi, 0 <= i < l.nEff
 * F.S. : Nilai kembalian elemen ke i dari l
 */
ElType getElmt(List l, int i){
    return l.contents[i];
}

/* Menetapkan nilai val ke elemen indeks ke-i
 * I.S. : List l terdefinisi, 0 <= i < l.nEff
 * F.S. : Set elemen ke-i dari l dengan val
 */
void setElmt(List *l, int i, ElType val){
    if (i >= 0 && i < l->nEff) {
        l->contents[i] = val;
    }
}

/* Menambahkan elemen di akhir list
 * I.S. : l terdefinisi, l.nEff < CAPACITY
 * F.S. : Elemen val ditambahkan di akhir elemen efektif l
 */
void insertLast(List *l, ElType val){
    l->contents[l->nEff] = val;
    l->nEff++;
}

/* Menghapus elemen di indeks ke-idx
 * I.S. : l terdefinisi, 0 <= idx < l.nEff
 * F.S. : Elemen di idx dihapus, elemen setelahnya digeser ke kiri
 */
void deleteAt(List *l, int idx){
    if(idx < l->nEff - 1) {
        for (int i = idx; i < l->nEff - 1; i++) {
            l->contents[i] = l->contents[i + 1];
        }
    }
    l->nEff--;
    l->contents[l->nEff] = IDX_UNDEF; // Set elemen terakhir menjadi IDX_UNDEF
}

