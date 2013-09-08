:- dynamic(s/2).

sigma(0, 0).
sigma(N, Sum):-
	s(N, Sum), !.
	
sigma(N, Sum):-
	N > 0,
	N1 is N - 1,
	sigma(N1,S1),
	Sum is S1 + N,
	assertz(s(N, Sum)).

