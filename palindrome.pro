rev([],X,X).      
rev([H|T], P, X):- rev(T, P, X1), append(X1, [H],X). 

eq([],[]).
eq([H|T],[A|B]):- H = A, eq(T, B).

palindrome([],[]).
palindrome(X):- rev(X, [], Z), eq(X, Z).

