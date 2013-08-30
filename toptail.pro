toptail([Head], [], []).

toptail([Head|Tail], InL, OutL):-
	toptail(Tail, InL, SubOutL),
	append([Head], SubOutL, OutL).

toptail([Head|Tail], X):- 
	toptail(Tail, [], X).
