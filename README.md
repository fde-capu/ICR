# ICR
## I CHING RINGS

(1) A loop (ring) of concatenated I Ching hexagrams passing through all 64 hexagrams without repetition.

(2) A bit must always be the closest approximation to the reference hexagram, that is, the last 6-bits formed figure must be as similar as possible to the first 6-bits.

Comments: (1) Many random solutions can be found. (2) Unique solution for each hexagram.

---

### Crossrefs and Facts

- References [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1], and [0, 0, 0, 0, 1, 0] coincide with [A169671](https://oeis.org/A169671) "Lexicographically earliest de Bruijn sequence for n = 6 and k = 2".

- Reference [1, 0, 0, 0, 0, 0] coincides with [A058342](https://oeis.org/A058342) "De Bruijn sequence of order 6: every window of size 6, [a(j),a(j+1),...,a(j+5)], shows a different 6-tuple, for 0 <= j <= 63.".

- A majority is solved in around 100~120 steps.

- References [0, 1, 1, 1, 1, 0] and [1, 0, 0, 0, 0, 1] need the most iterations: 278483150.

- References [0, 1, 0, 1, 1, 1] and [1, 0, 1, 0, 0, 0] need the least iterations of 89.

### Pseudo-code

	for each bit position, starting at empty after the reference:
		if there is no value, find the *best_match*.
		if it forms a repeated hexagram, try inverting the bit at current position.
		if it is still a repeated figure,
			go back to the last bit that has not been inverted.
			Reset all bits on the way.
			Invert the new position.
		if it is not a repeated hexagram, move forward.
		if all positions are fullfilled and there are no repetitions, stop.

	*best_match* function:
		// hexagrams are 6-bit, so only need to match from below 4 bits.
		take in account the last four digits:
			if it matchs the first four, return the 5th.
			if it matches the digits 2, 3, 4, 5, return the 6th.
		take in account the last three digits:
			if it match the first three digits, return the 4th.
			if it match the digits 2, 3, 4, return the 5th.
			if it match the digits 3, 4, 5, return the 6th
		// (...) use the same method for two and one digit.
		if nothing matches, return digit number 1.

### Usage

`# make`

then

`# ./icr.a hexagram`

where *hexagram* is a six-digit binary notation from `000000` through `111111`.

### But a finite sequence with and arbitrarly method is not of general interest, and they correspond to de Brujin's anyway.

Consider a state of hexagram that wants to be in fixed position at all time. It expects a new line to form a new hexagram as similar as itself as possible. Thus, each formed ring is an expression of the relation of one with all others. Beauty in finit.

These are a set of de Brujin's algorithm, a class with the singular property of being centralized on a reference hexagram.

### What about the method?

Largest best match wins. If the hexagram is repeated, step back recursively. Match the end to connect to the beginning (to form a ring).

### Why?

First, art and fun. Second, is this a piece of nature? Third, some sort of quantic cosmos for wondering through an inner chaos. Forth, did I just write that?

I find myself under the impression that many analysis may result from the found results. Groups, sub-families, areas of similarity, the outcome of reverses, traces of self and collective symmetry, common blocks (I like to name them), and many more keep popping in my head. *Please support this research.*

### More?

I call these the *natural positions* of I Ching rings. There are also *random* positions.

I am afraid to have arbitrarly chosen 6-bit parts. The same logic would also make sense on any N-bit system. Some of the code was written with this in mind, but it is experimental.

### Trivias

de Bruijin's coincidences.

A `Javascript` code was originaly written in 2015 on a cellphone while travelling by subway back and forth to work in São Paulo city. Also, many of the rings, even some with long iterations, were first computed by the phone hardware. It was *really* slow.

The _I Ching_, known as _The Book of Changes_, is an ancient oracle and divination system, one of the oldest books of humanity. It implies *meanings* to each six bit figures, and claims these hexagrams change through the flow of life. Bits are referred as *yin* and *yang*.

Collars made out of two types of stone representing *yin* and *yang* in a never repeating hexagram order have existed and have served as amulets in the past. To my knowledge, there is no record of a *natural position* criteria for each hexagram; I understand these collars were randomly assembled. Please let me know if you know more about it.

### To-do

- Iteration counter.
- Visual mode (slower, while you could see it in action).
- Chronometer.
- Generalize for any `k` and `n`.

---

Copyright 2020 fde-capu

This is authorial and original work. If you find it profitable or useful in any form, you are not allowed to use it without my authorization; just reach out to me to settle things down - of course I would like to know! If you are here out of intellectual interest, feel free to comment and contribute.
