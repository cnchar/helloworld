double([], []).

double([Head|Tail], [Head,Head|T]):-
	double(Tail, T).
