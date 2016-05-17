main :: IO ()
main = do
	inp <- getLine
	let [a,b,c] = map read (words inp) :: [Integer]
	putStrLn (solve a b c)
	return ()

solve :: Integer -> Integer -> Integer -> String
solve a b c
	| c==0 && a==b 					   = "YES"
	| c==0 && a/=b 					   = "NO"
	| (b-a)`mod`c==0 && (b-a)`div`c>=0 = "YES"
    | otherwise 					   = "NO"
