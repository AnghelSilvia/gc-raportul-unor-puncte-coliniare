# gc-raportul-unor-puncte-coliniare

Cerinta: Raportul unor puncte coliniare (5p) Se dau patru puncte coliniare. Sa se determine acele trei puncte pentru care valoarea raportului este maxima (in raport cu toate valorile obtinute pentru cele patru puncte).

Am implementat o solutie generala, cu un numar variabil de puncte si dimensiuni (cu toate ca mai mult de trei dimensiuni sunt de neinteles pentru noi, oamenii, mi s-a parut interesant sa abordez problema si din aceasta perspectiva).

Programul citeste input-ul dintr-un fisier (nr. de dimensiuni, nr. de puncte, si apoi coordonatele pentru puncte).
Este indeajuns sa sortam punctele in functie de prima coordonata, deoarece acestea sunt coliniare.
Avand punctele sortate, daca le comparam in ordine crescatoare sau descrescatoare vom obtine doar rapoartele pozitive;
  (de ex. sa zicem ca punctele M, N, P se afla in aceasta ordine pe dreapta. r(M, N, P) si r(P, N, M) sunt pozitive, pentru restul raportul este negativ.)
Declaram o variabila maxRatio (initial 0) si comparam rapoartele obtinute cu aceasta. De fiecare data cand gasim un raport mai mare, il retinem, si retinem si punctele (in ordinea corecta, bineinteles).
Ramane de afisat raportul maxim si cele 3 puncte aferente lui.
