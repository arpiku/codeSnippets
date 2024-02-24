 data Tree a = Leaf | Node (Tree a) a (Tree a)

 insert :: Ord a => a -> Tree a -> Tree a
 insert x Leaf = Node Leaf x Leaf
 insert x (Node t y s)
     | x <= y = Node (insert x t) y s
     | x > y  = Node t y (insert x s)

 flatten :: Tree a -> [a]
 flatten Leaf = []
 flatten (Node t x s) = flatten t ++ [x] ++ flatten s

 treesort :: Ord a => [a] -> [a]
 treesort = flatten . foldr insert Leaf
