-- Following is a list of different varients of Merge Sort implemented in Haskell.

splitInHalf :: [a] -> ([a], [a])
splitInHalf xs = splitAt (length xs `div` 2) xs

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
  | x <= y    = x : merge xs (y:ys)
  | otherwise = y : merge (x:xs) ys

mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = let (left, right) = splitInHalf xs
               in merge (mergeSort left) (mergeSort right)


--Man! Code is a good way to share complex shit fast!

merge_sort :: [a] -> [a]
merge_sort([])  = []
merge_sort([x]) = [x]
merge_sort(xs)  = merge(merge_sort(left), merge_sort(right))
  where (left, right) = split(xs, length(xs) / 2)
  
merge :: ([a], [a]) -> [a]
merge([], xs) = xs
merge(xs, []) = xs
merge(x : xs, y : ys) 
   | if x ≤ y = x : merge(xs, y : ys)
   | else     = y : merge(x : xs, ys)


