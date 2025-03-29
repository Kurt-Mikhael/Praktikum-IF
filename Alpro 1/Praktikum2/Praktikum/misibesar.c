#include <stdio.h>

/**
 * Fungsi untuk mengecek apakah tahun kabisat
 * Untuk tahun kelipatan 100, tahun kabisat harus habis dibagi 400
 * Untuk tahun selain kelipatan 100, tahun kabisat harus habis dibagi 4
 * @param year Tahun
 * @return Mengembalikan 1 jika tahun kabisat, 0 jika tidak
 */
int isLeapYear(int year)
{
  // TODO: Implementasi fungsi isLeapYear
  if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return 1;
  return 0;
}

/**
 * Fungsi untuk mendapatkan jumlah hari dalam suatu bulan
 * @param month Bulan (dalam rentang 1-12)
 * @param year Tahun
 * @return Mengembalikan jumlah hari dalam bulan tersebut
 */
int getDaysInMonth(int month, int year)
{
  // TODO: Implementasi fungsi getDaysInMonth
  if (month == 2) {
    if (isLeapYear(year)) {
        return 29;
    } else return 28;
  } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
  else return 30;
}

/**
 * Mengembalikan apakah tanggal valid
 * Tanggal yang valid mengikuti aturan berikut:
 * - 1 <= day <= jumlah hari dalam bulan
 * - 1 <= month <= 12
 * - year >= 1
 * @param day The day
 * @param month The month
 * @param year The year
 * @return mengembalikan 1 jika tanggal valid, 0 jika tidak
 */
int isValidDate(int day, int month, int year)
{
  // TODO: Implementasi fungsi isValidDate
  if (year < 1 || month < 1 || month > 12) return 0;
  if (1 <= day && day <= getDaysInMonth(month, year)) {
    return 1;
  } else return 0;
}

/**
 * Fungsi untuk menghitung jumlah hari sejak awal, yaitu day = 1, month = 1, year = 1
 * @param day Hari
 * @param month Bulan
 * @param year Tahun
 * @return Mengembalikan jumlah hari sejak awal
 */
long long daysFromBeginning(int day, int month, int year)
{
  // TODO: Implementasi fungsi daysFromBeginning
  int total = 0;
  for (int i = 1; i <= year - 1; i++) {
    if (isLeapYear(i) == 1) total += 366;
    else total += 365;
  }
  for (int i = 1; i <= month - 1; i++) {
    total += getDaysInMonth(i, year);
  }
  total += day-1;
  return total;
}

/**
 * Fungsi untuk menghitung perbedaan hari dari dua tanggal yang valid (tanggal 2 - tanggal 1)
 * Note: input tanggal sudah valid
 * @param d1 Hari dari tanggal pertama
 * @param m1 Bulan dari tanggal pertama
 * @param y1 Tahun dari tanggal pertama
 * @param d2 Hari dari tanggal kedua
 * @param m2 Bulan dari tanggal kedua
 * @param y2 Tahun dari tanggal kedua
 * @return Mengembalikan perbedaan hari dari tanggal 2 - tanggal 1
 */
long long dateDifference(int d1, int m1, int y1, int d2, int m2, int y2)
{
  // TODO: Implementasi fungsi dateDifference
  return daysFromBeginning(d2,m2,y2)-daysFromBeginning(d1,m1,y1);
}

/**
 * Program utama:
 * - Menerima input d1,m1,y1
 * - Validasi tanggal pertama sampai input valid
 * - Menerima input d2,m2,y2
 * - Validasi tanggal kedua sampai input valid dan tanggal kedua lebih besar atau sama dengan dari tanggal pertama
 * - Mengeluarkan output selisih hari dari tanggal kedua - tanggal pertama
 */
int main()
{
  // TODO: Implementasi program utama
  int d1, m1, y1, d2, m2, y2;
  scanf("%d %d %d", &d1, &m1, &y1);
  while (!isValidDate(d1,m1,y1)) {
    printf("Tanggal tidak valid\n");
    scanf("%d %d %d", &d1, &m1, &y1);
  }
  scanf("%d %d %d", &d2, &m2, &y2);
  
  while(isValidDate(d2,m2,y2)==0 || dateDifference(d1,m1,y1,d2,m2,y2)<0){
    if(isValidDate(d2,m2,y2)==0){
      printf("Tanggal tidak valid\n");
    } else{
        printf("Tanggal kedua lebih dulu\n");
    }
    scanf("%d %d %d", &d2, &m2, &y2);
  }
  printf("%lld\n", dateDifference(d1,m1,y1,d2,m2,y2));
  return 0;
}