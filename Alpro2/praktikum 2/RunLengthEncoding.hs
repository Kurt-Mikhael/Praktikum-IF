module RunLengthEncoding where
import Control.Concurrent (Chan)

next :: String -> Char -> String
next s c =
    if null s then
        ""
    else
        if head s /= c then
            s
        else
            next (tail s) c

countChar :: String -> Char -> Int
countChar s c =
    if null s then
        0
    else
        if head s /= c then
            0
        else
            1 + countChar (tail s) c

runLengthEncoding :: String -> [(Char, Int)]
runLengthEncoding s = 
    if null s then
        []
    else
        [(head s , countChar s (head s))] ++ runLengthEncoding (next s (head s))
