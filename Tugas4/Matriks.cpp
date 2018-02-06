#include <iostream>
#include "Matriks.h"

// ctor inisialisasi n_brs dan n_kol dengan ctor initialization list, N=M=defsize
// Seluruh elemen matriks diinisialisasi dengan nilai 0
Matriks::Matriks():n_kol(DEFSIZE),n_brs(DEFSIZE) {
	//KAMUS
	int i,j;
	//ALGORITMA
	b=new int[n_brs];
	for(i=0;i<n_brs;i++) {
		b[i]=new int[n_kol];
	}
	for(i=0;i<n_brs;i++) {
		for(j=0;j<n_kol;j++) {
			b[i][j]=0;
		}
	}
}

// ctor dengan param n (banyaknya baris) dan m (banyaknya kolom)
// Seluruh elemen matriks diinisialisasi dengan nilai 0
Matriks::Matriks(int n, int m):n_kol(m),n_brs(n) {
	//KAMUS
	int i,j;
	//ALGORITMA
	b=new int[n_brs];
	for(i=0;i<n_brs;i++) {
		b[i]=new int[n_kol];
	}
	for(i=0;i<n_brs;i++) {
		for(j=0;j<n_kol;j++) {
			b[i][j]=0;
		}
	}
}

// cctor
Matriks::Matriks(const Matriks& m):n_kol(m.n_kol),n_brs(m.n_brs) {
	//KAMUS
	int i,j;

	//ALGORITMA
	b=new int[n_brs];
	for(i=0;i<n_brs;i++) {
		b[i]=new int[n_kol];
	}
	for(i=0;i<n_brs;i++) {
		for(j=0;j<n_kol;j++) {
			b[i][j]=m[i][j];
		}
	}
}

// dtor
Matriks::~Matriks() {
	//KAMUS
	int i;
	//ALGORITMA
	for(i=0;i<n_kol;i++) {
		delete[] b[i];
	}
	delete[] b;
}

// operator= menjamin tidak bitwise copy.
// dan dapat melakukan assignment m1=m2; prekondisi: ukuran m1=ukuran m2
Matriks& Matriks::operator= (Matriks& m):n_brs(m.n_brs),n_kol(m.n_kol) {
	//KAMUS
	int i,j;

	//ALGORITMA
	for(i=0;i<n_kol;i++) {
		delete[] b[i];
	}
	delete[] b;

	b=new int[n_brs];
	for(i=0;i<n_brs;i++) {
		b[i]=new int[n_kol];
	}
	for(i=0;i<n_brs;i++) {
		for(j=0;j<n_kol;j++) {
			b[i][j]=m[i][j];
		}
	}
	return(*this);
}

// test apakah ukuran sama: true jika m1.n_brs== m2.n_brs && m1.n_kol== m2.n_kol
friend bool Matriks::IsEqSize (Matriks m1, Matriks m2) {
	//KAMUS

	//ALGORITMA
}

// operator+ penjumlahan nilai b dari kedua matriksyg posisinya sama
// Mhasil(i,j) = M1 (i,j) + M2(i,j)
// Proses : jika ukuran m2 tak sama dengan current object,
// yang tak beririsan tidak dijumlahkan, hanya dicopy
// hasilnya adalah matriks yang lebih besar
// ditulis sebagai function member
Matriks& Matriks::operator+ (Matriks m2) {
	//KAMUS

	//ALGORITMA
}

// operator* untuk melakukan perkalian thd setiap nilai b yang posisinya sama
// Mhasil(i,j) = M1 (i,j) * M2(i,j)
// jika matriks ukurannya tak sama, yang tak beririsan tak dikalikan
// hasilnya adalah matriks yang lebih besar ukurannya
// Ditulis sebagai friend function
friend Matriks& Matriks::operator* (const Matriks& m1, const Matriks& m2) {
	//KAMUS

	//ALGORITMA
}

// menulis ukuran dan isi Matriks (lihat contoh
friend std::ostream& Matriks::operator<<(std::ostream &os, const Matriks& m) {
	//KAMUS

	//ALGORITMA
}

// isikan nilai v di posisi data[i,j], i dan j terdefinisi
void Matriks::SetData (int i, int j, int v) {
	//KAMUS

	//ALGORITMA
	b[i][j]=v;
}

// ambil elemen v di posisi data[i,j], i dan j terdefinisi
int Matriks::GetData (int i, int j) {
	//KAMUS

	//ALGORITMA
	return(b[i][j]);
}

// Mengembalikan n_brs
int Matriks::GetBrs() {
	// Mengembalikan n_kol

	//KAMUS

	//ALGORITMA
	retrun(n_brs);
}

int Matriks::GetKol() {
	//KAMUS

	//ALGORITMA
	retrun(n_kol);
}
