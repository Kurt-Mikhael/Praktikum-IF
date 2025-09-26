module Segitiga where

-- DEFINISI DAN SPESIFIKASI
data Segitiga = Segitiga Float Float Float
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- sisi1: segitiga -> Float
-- {sisi1(S) memberikan sisi pertama dari segitiga S}
sisi1 :: Segitiga -> Float
sisi1 (Segitiga a _ _) = a
-- sisi2: segitiga -> Float
-- {sisi2(S) memberikan sisi kedua dari segitiga S}
sisi2 :: Segitiga -> Float
sisi2 (Segitiga _ b _) = b
-- sisi3: segitiga -> Float
-- {sisi3(S) memberikan sisi ketiga dari segitiga S}
sisi3 :: Segitiga -> Float
sisi3 (Segitiga _ _ c) = c

maxSisi :: Segitiga -> Float
maxSisi (Segitiga a b c) = 
    if a >= b && a >= c then a
    else if b >= a && b >= c then b
    else c

minSisi :: Segitiga -> Float
minSisi (Segitiga a b c) = 
    if a <= b && a <= c then a
    else if b <= a && b <= c then b
    else c


-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makeSegitiga: 3 Float -> segitiga
-- {makeSegitiga(a,b,c) membentuk sebuah segitiga dari a, b, dan c dengan a, b, dan c adalah panjang sisi-sisi segitiga}
makeSegitiga :: Float -> Float -> Float -> Segitiga
makeSegitiga a b c = Segitiga a b c
-- DEFINISI DAN SPESIFIKASI PREDIKAT
-- isSegitiga: segitiga -> boolean
-- {isSegitiga(S) benar jika S adalah segitiga yang valid}
isSegitiga :: Segitiga -> Bool
isSegitiga (Segitiga a b c) = a + b > c && a + c > b && b + c > a

-- DEFINISI OPERATOR/FUNGSI LAIN TERHADAP SEGITIGA
-- keliling: segitiga -> Float
-- {keliling(S) menghitung keliling segitiga S}
keliling :: Segitiga -> Float
keliling (Segitiga a b c) = a + b + c
-- luas: segitiga -> Float
-- {luas(S) menghitung luas segitiga S}
luas :: Segitiga -> Float
luas (Segitiga a b c) = 
    let s = (a + b + c) / 2
    in sqrt (s * (s - a) * (s - b) * (s - c))
-- isSamaSisi: segitiga -> boolean
-- {isSamaSisi(S) benar jika S adalah segitiga sama sisi}
isSamaSisi :: Segitiga -> Bool
isSamaSisi (Segitiga a b c) = a == b && b == c
-- isSamaKaki: segitiga -> boolean
-- {isSamaKaki(S) benar jika S adalah segitiga sama kaki}
isSamaKaki :: Segitiga -> Bool
isSamaKaki (Segitiga a b c) = a == b || a == c || b == c
-- isSiku: segitiga -> boolean
-- {isSiku(S) benar jika S adalah segitiga siku-siku}
isSiku :: Segitiga -> Bool
isSiku (Segitiga a b c) = 
    let m = maxSisi (Segitiga a b c)
        n = minSisi (Segitiga a b c)
        mid = a + b + c - m - n
    in m * m == n * n + mid * mid

