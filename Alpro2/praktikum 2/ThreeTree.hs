module ThreeTree where

threeTree :: [Int] -> [Int]
threeTree li = 
    if null li then []
    else 
        if head li `mod` 3 == 0 then
            [head li] ++ threeTree(tail li)
        else 
            threeTree(tail li)