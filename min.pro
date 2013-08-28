min([], X, X).

min([Head|Tail], T, Min):-
	Head < T,
    min(Tail, Head, Min).

min([Head|Tail], T, Min):-
	Head >= T,
    min(Tail, T, Min).

min([Head|Tail], Min):-
	min(Tail, Head, Min).
