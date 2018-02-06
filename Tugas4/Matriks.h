#ifndef MATRIKS_H
#define MATRIKS_H
#define DEFSIZE 100

#include <iostream>

class Matriks {
	public:
		// ctor inisialisasi n_brs dan n_kol dengan ctor initialization list, N=M=defsize
		// Seluruh elemen matriks diinisialisasi dengan nilai 0
		Matriks();

		// ctor dengan param n (banyaknya baris) dan m (banyaknya kolom)
		// Seluruh elemen matriks diinisialisasi dengan nilai 0
		Matriks(int n, int m);

		// cctor
		Matriks(const Matriks& m);

		// dtor
		~Matriks();

		// operator= menjamin tidak bitwise copy.
		// dan dapat melakukan assignment m1=m2; prekondisi: ukuran m1=ukuran m2
		Matriks& operator= (Matriks& m);

		// test apakah ukuran sama: true jika m1.n_brs== m2.n_brs && m1.n_kol== m2.n_kol
		friend bool IsEqSize (Matriks m1, Matriks m2);

		// operator+ penjumlahan nilai b dari kedua matriksyg posisinya sama
		// Mhasil(i,j) = M1 (i,j) + M2(i,j)
		// Proses : jika ukuran m2 tak sama dengan current object,
		// yang tak beririsan tidak dijumlahkan, hanya dicopy
		// hasilnya adalah matriks yang lebih besar
		// ditulis sebagai function member
		Matriks& operator+ (Matriks m2);

		// operator* untuk melakukan perkalian thd setiap nilai b yang posisinya sama
		// Mhasil(i,j) = M1 (i,j) * M2(i,j)
		// jika matriks ukurannya tak sama, yang tak beririsan tak dikalikan
		// hasilnya adalah matriks yang lebih besar ukurannya
		// Ditulis sebagai friend function
		friend Matriks& operator* (const Matriks& m1, const Matriks& m2);

		// menulis ukuran dan isi Matriks (lihat contoh
		friend std::ostream& operator<<(std::ostream &os, const Matriks& m);

		// isikan nilai v di posisi data[i,j], i dan j terdefinisi
		void SetData (int i, int j, int v);

		// ambil elemen v di posisi data[i,j], i dan j terdefinisi
		int GetData (int i, int j);

		// Mengembalikan n_brs
		int GetBrs();
		// Mengembalikan n_kol
		int GetKol();

	protected:
		const int n_brs; // Banyaknya baris, n_brs > 0
		const int n_kol; // Banyaknya kolom, n_kol > 0
		int ** b; // Elemen matriks
};
#endif
