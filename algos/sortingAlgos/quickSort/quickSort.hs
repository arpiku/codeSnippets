
quickSort :: Ord a => [a] -> [a]
quickSort xs =
  case xs of
    [] -> []
    [x] -> [x]
    pivot:rest ->
      let smaller = quickSort [y | y <- rest, y <= pivot]
          larger  = quickSort [y | y <- rest, y > pivot]
      in smaller ++ [pivot] ++ larger

quickSortv2 :: Ord a => [a] -> [a]
quickSortv2 [] = []
quickSortv2 [x] = [x]
quickSortv2 (x:xs) = quickSortv2 [y | y<-xs, y <= x] ++ [x] ++ quickSortv2[y | y <-xs, y > x]


