module Mahasiswa where

-- TYPE MAHASISWA
-- DEFINISI TYPE
-- type mahasiswa: <nama: String, nim: String, ipk: Float>
-- {<nama, nim, ipk> adalah sebuah mahasiswa, dengan nama adalah nama mahasiswa,
--  nim adalah nomor induk mahasiswa, ipk adalah nilai IPK mahasiswa}

data Mahasiswa = Mahasiswa String String Float
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- nama: mahasiswa -> String
-- {nama(M) memberikan nama Mahasiswa M}
nama :: Mahasiswa -> String
nama (Mahasiswa nama _ _) = nama

-- nim: mahasiswa -> String
-- {nim(M) memberikan NIM Mahasiswa M}
nim :: Mahasiswa -> String
nim (Mahasiswa _ nim _) = nim

-- ipk: mahasiswa -> Float
-- {ipk(M) memberikan IPK Mahasiswa M}
ipk :: Mahasiswa -> Float
ipk (Mahasiswa _ _ ipk) = ipk

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makeMahasiswa: String -> String -> Float -> mahasiswa
-- {makeMahasiswa(nama,nim,ipk) membentuk Mahasiswa baru}
makeMahasiswa :: String -> String -> Float -> Mahasiswa
makeMahasiswa nama nim ipk = (Mahasiswa nama nim ipk)

-- DEFINISI DAN SPESIFIKASI PREDIKAT
-- isValidMahasiswa: mahasiswa -> boolean
-- {isValidMahasiswa(M) benar jika M memiliki Nama, NIM tidak kosong dan IPK antara 0.0 s.d. 4.0}
isValidMahasiswa :: Mahasiswa -> Bool
isValidMahasiswa (Mahasiswa nama nim ipk) = not (null nama) && not (null nim) && ipk >= 0.0 && ipk <= 4.0
-- TODO --

-- DEFINISI OPERATOR/FUNGSI LAIN TERHADAP MAHASISWA
-- gantiIPK: mahasiswa -> Float -> mahasiswa
-- {gantiIPK(M,ipkBaru) mengganti IPK mahasiswa M dengan ipkBaru (maksimal 4.0)}
gantiIPK :: Mahasiswa -> Float -> Mahasiswa
gantiIPK (Mahasiswa nama nim _) ipkBaru = 
    let newIpk  =   if ipkBaru > 4.0 then 4.0 
                    else if ipkBaru < 0.0 then 0.0 
                    else ipkBaru 
    in (Mahasiswa nama nim newIpk)

-- klasifikasiMahasiswa: mahasiswa -> String
-- {klasifikasiMahasiswa(M) memberikan predikat mahasiswa berdasarkan IPK}
-- Dengan ketentuan:
-- IPK >= 3.51 : "Cumlaude"
-- 3.00 <= IPK < 3.51 : "Sangat Memuaskan"
-- 2.75 <= IPK < 3.00 : "Memuaskan"
-- IPK < 2.75 : "Perlu Perbaikan"
klasifikasiMahasiswa :: Mahasiswa -> String
klasifikasiMahasiswa (Mahasiswa _ _ ipk)
  | ipk >= 3.51 = "Cumlaude"
  | ipk >= 3.00 = "Sangat Memuaskan"
  | ipk >= 2.75 = "Memuaskan"
  | otherwise   = "Perlu Perbaikan"

-- tampilMahasiswa: mahasiswa -> String
-- {tampilMahasiswa(M) mengubah Mahasiswa M menjadi string deskriptif}
-- Dengan format:
-- "Nama: <nama>, NIM: <nim>, IPK: <ipk>"
tampilMahasiswa :: Mahasiswa -> String
tampilMahasiswa (Mahasiswa nama nim ipk) = "Nama: " ++ nama ++ ", NIM: " ++ nim ++ ", IPK: " ++ show ipk