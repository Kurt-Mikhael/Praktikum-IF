module SecondLargest where
max2 :: Int -> Int -> Int
max2 a b = 
    if a >= b then a
    else b

largest :: [Int] -> Int
largest li =
    if null (tail li) then head li
    else 
        max2 (head li) (largest (tail li))

deleteX :: [Int] -> Int -> [Int]
deleteX li x =
    if null li then []
    else 
        if head li == x then 
            tail li
        else 
            [head li] ++ deleteX (tail li ) x

secondLargest :: [Int] -> Int 
secondLargest li = largest (deleteX li (largest li))