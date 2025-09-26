module SegiEmpat where

-- DEFINISi Tipe
data Point = Point Float Float
  deriving (Show, Eq)
data SegiEmpat = SegiEmpat Point Point Point Point
  deriving (Show, Eq)

-- DEFINISI DAN SPESIFIKASI SELEKTOR
-- titik1: SegiEmpat -> Point
titik1 :: SegiEmpat -> Point
titik1 (SegiEmpat p1 _ _ _) = p1
-- titik2: SegiEmpat -> Point
titik2 :: SegiEmpat -> Point
titik2 (SegiEmpat _ p2 _ _) = p2
-- titik3: SegiEmpat -> Point
titik3 :: SegiEmpat -> Point
titik3 (SegiEmpat _ _ p3 _) = p3
-- titik4: SegiEmpat -> Point
titik4 :: SegiEmpat -> Point
titik4 (SegiEmpat _ _ _ p4) = p4

-- DEFINISI DAN SPESIFIKASI KONSTRUKTOR
-- makeSegiEmpat: Point -> Point -> Point -> Point -> SegiEmpat
makeSegiEmpat :: Point -> Point -> Point -> Point -> SegiEmpat
makeSegiEmpat p1 p2 p3 p4 = SegiEmpat p1 p2 p3 p4

-- DEFINISI DAN SPESIFIKASI PREDIKAT
-- isSegiEmpat: SegiEmpat -> Bool
-- {isSegiEmpat(S) benar jika S adalah segi empat yang valid}
isSegiEmpat :: SegiEmpat -> Bool
isSegiEmpat (SegiEmpat (Point x1 y1) (Point x2 y2) (Point x3 y3) (Point x4 y4)) =
    let d1 = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
        d2 = (x3 - x2) * (y4 - y2) - (y3 - y2) * (x4 - x2)
        d3 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)
        d4 = (x1 - x4) * (y2 - y4) - (y1 - y4) * (x2 - x4)
    in  (d1 > 0 && d2 > 0 && d3 > 0 && d4 > 0)

isPersegi :: SegiEmpat -> Bool
isPersegi (SegiEmpat (Point x1 y1) (Point x2 y2) (Point x3 y3) (Point x4 y4)) =
    let
        dx1 = x2 - x1
        dy1 = y2 - y1
        dx2 = x3 - x2
        dy2 = y3 - y2
        dx3 = x4 - x3
        dy3 = y4 - y3
        dx4 = x1 - x4
        dy4 = y1 - y4
    in  (dx1 == dy1 && dx2 == dy2 && dx3 == dy3 && dx4 == dy4) || (dx1 == -dy1 && dx2 == -dy2 && dx3 == -dy3 && dx4 == -dy4)


