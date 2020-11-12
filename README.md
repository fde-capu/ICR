# ICR
## I CHING RINGS

(1) A loop (ring) of concatenated I Ching hexagrams passing through all 64 hexagrams without repetition.

(2) A bit must always be the closest approximation to the reference hexagram, that is, the last 6-bits formed figure must be as similar as possible to the first 6-bits.

Comments: (1) Many random solutions can be found. (2) Only one solution possible for each hexagram.

Initial algorithm needs at least 89 steps (unique case for [0, 1, 0, 1, 1, 1] and [1, 0, 1, 0, 0, 0]. Most are solved around 100~120 steps. Four reciprocal exceptions take 809, 1226801, 1180856 and 278483150 steps (the last being for [1, 0, 0, 0, 0, 1] and [0, 1, 1, 1, 1, 0]).

*The sequence based on reference [0, 0, 0, 0, 0, 0], and its reciprocal [1, 1, 1, 1, 1, 1], coincides with [A169671](https://oeis.org/A169671) "Lexicographically earliest de Bruijn sequence for n = 6 and k = 2".*

---

### Usage

`# make`

then

`# ./icr.a _hexagram_`

where _hexagram_ is a binary notation from `000000` through `111111`.

Set the `var tic = x;` where `x` is the value of milliseconds between each iteration, if you want to watch the ring building process closely.

#### What about the other files?

- `ICbitmap.js` writes a qrcodesque `.bmp` file representing all rings.
- I do not know what `ICgroups.js` (deprecated, present only on the first commit) does; but I am under the impression many analysis may result from the found results. Groups, sub-families, areas of similarity, the outcome of reverses, traces of self and collective symmetry, common blocks (I like to name them), and many more. *Please support this research.*
- `ref.txt` is just a plain notation of all ICRs so you do not have to compute it every time.

### But a finite sequence with and arbitrarly method is not of general interest, and they correspond to de Brujin's anyway.

Consider a state of hexagram that wants to be in fixed position at all time. It expects a new line to form a new hexagram as similar as itself as possible. Thus, each formed ring is an expression of the relation of one with all others. Beauty in finit.

So, these would be a set of de Brujin's algorithm, a class with this singular property.

### What about the method?

Largest best match wins. If the hexagram is repeated, step back recursively. Match the end to connect to the beginning (to form a ring).

### Why?

First, art and fun. Second, is this a piece of nature? Third, some sort of quantic cosmos for wondering through an inner chaos. Forth, did I just write that? Thinking artificially.

### More?

I call these the *natural positions* of I Ching rings.

I am afraid to have arbitrarly chosen 6-bit parts. The same logic would also make sense on any N-bit system.

### Trivias?

de Bruijin's coincidence.

The `.js` code was originaly written in 2015 on a cellphone while travelling by subway back and forth to work in São Paulo city. Also, the many of the rings, even some long iterations, were first computed by this hardware.

The _I Ching_, known as _The Book of Changes_, is an ancient oracle and divination system, one of the oldest books of humanity. It implies *meanings* to each six bit figures, and claims these hexagrams change through the flow of life. Bits are referred as *yin* and *yang*.

Collars made out of two types of stone representing *yin* and *yang* in a never repeating hexagram order have existed and have served as amulets in the past. To my knowledge, there is no record of a *natural position* criteria for each hexagram; I understand these collars were randomly assembled. Please let me know if you know more about it.

### To-do

- Iteration counter.
- Visual mode (slower, but you can see it working).
- Chronometer.
- Generalize for any `k` and `n`.

---

Copyright 2020 fde-capu

This is authorial and original work. If you find it profitable or useful in any form, you are not allowed to use it without my authorization; just reach out to me to settle things down - of course I would like to know! If you are here out of intellectual interest, feel free to comment and contribute.
