# ICR
## I CHING RINGS

(1) A loop (ring) of concatenated I Ching hexagrams passing through all 64 hexagrams without repetition.

(2) A bit must always be the closest approximation to the reference hexagram, that is, the last 6-bits formed figure must be as similar as possible to the first 6-bits.

(3) The method gives 64 results, 32 of which have inverted reciprocals within the family.

(4) Each solution requires more or less iterations to solve.

Comments: (1) Many random solutions can be found, yet to be categorized and counted. (2) Only one solution possible for each hexagram. (3) Optimally, the whole family is interpreted as reciprocals different from each other. (4) Initial algorithm needs at least 89 steps (unique case for "0, 1, 0, 1, 1, 1" and "1, 0, 1, 0, 0, 0"). Most are solved around 100~120 steps. Four reciprocal exceptions take 809, 1226801, 1180856 and 278483150 steps (the last being for "1, 0, 0, 0, 0, 1" and "0, 1, 1, 1, 1, 0").

*The first sequence, based on "0, 0, 0, 0, 0, 0", and its reciprocal "1, 1, 1, 1, 1, 1", coincides with A169671 "Lexicographically earliest de Bruijn sequence for n = 6 and k = 2".*

---

### This `ICR.js`, how do I use it?

Look at the commented `ref="(...);"` section within the file. Leave all comments (`//`), and uncomment only the reference you want to run. Open `index.htm` on a web browser. Wait for the result, it might take a little while.

Set the `var tic = x;` where `x` is the value of milliseconds between each iteration, if you want to watch the ring building process closely.

#### But the code is a mess!

Yep; it was written two or more years ago with no formalities whatsoever. Besides, it is a file you _should_ want to play around.

##### It would be so much more efficient if...

...do not tell, I know, someday I will code it neatier. I promise a `C` file at any time.

#### What about the other files?

- `ICbitmap.js` writes a qrcodesque `.bmp` file representing all rings.
- I do not know what `ICgroups.js` (deprecated, present only on the first commit) does; but I am under the impression many analysis may result from the found results. Groups, sub-families, areas of similarity, the outcome of reverses, traces of self and collective symmetry, common blocks (I like to name them), and many more. *Please support this research.*
- `ref.txt` is just a plain notation of all ICRs so you do not have to compute it every time.

### But a finite sequence with and arbitrarly method is not of general interest, and they correspond to de Brujin's anyway.

In short, this was the OIES response I have got. "Whatever this is", they say.

Imagine a state of hexagram that wants to be in fixed position at all time. It expects a new line to form a new hexagram as similar as itself as possible. Thus, each formed ring is an expression of the relation of one with all others. Beauty in finit.

So, these would be a set of de Brujin's algorithm, a class with special properties.

Due to the OEIS rejection, the sequences must be considered more a piece of composition than an empirical finding. _Meh_! They remain very sound to me! 

### What about the method?

Not being a mathematician myself makes it harder to describe the algorithm in a consise way. Largest best match wins. If the hexagram is repeated, step back recursively. Match the end to connect to the beginning.

### Why?

First, art and fun. Second, is this a piece of nature? Third, some sort of quantic cosmos for wondering through an inner chaos. Forth, did I just write that? Thinking artificially.

### More?

I call these the *natural positions* of I Ching rings.

I am afraid to have arbitrarly chosen 6-bit parts. The same logic would also make sense on any N-bit system.

### Trivias?

de Bruijin's coincidence.

The _I Ching_, known as _The Book of Changes_, is an ancient oracle and divination system, one of the oldest books of humanity. It implies *meanings* to each six bit figures, and claims these hexagrams change through the flow of life. Bits are referred as *yin* and *yang*.

Collars made out of two types of stone representing *yin* and *yang* in a never repeating hexagram order have existed and have served as amulets in the past. To my knowledge, there is no record of a *natural position* criteria for each hexagram; I understand these collars were randomly assembled. Please let me know if you know more about it.

---

Copyright 2020 fde-capu

This is authorial and original work. If you find it profitable or useful in any form, you are not allowed to use it without my authorization; just reach out to me to settle things down - of course I would like to know! If you are here out of intellectual interest, feel free to comment and contribute.
