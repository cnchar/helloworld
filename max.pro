max([], X, X).

max([Head|Tail], T, Min):-
	Head < T,
    max(Tail, T, Min).

max([Head|Tail], T, Min):-
	Head >= T,
    max(Tail, Head, Min).

max([Head|Tail], Min):-
	max(Tail, Head, Min).
