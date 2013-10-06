/*
 *   From Programming Pearls.
 */
#ifndef __BITVECTOR_H__
#define __BITVECTOR_H__

// C
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

class BitVector {
    public:
        BitVector() {
            m_size  = 0;
            m_count = 0;
        }

        BitVector(int maxValue) {
            assert(maxValue > 0);
            m_size = maxValue;
            m_sets = (int *)malloc( (m_size/BITS_PER_WORD + 1) * sizeof(int));
            assert(m_sets != NULL);
            clear();
            m_count = 0;
        }

        ~BitVector() {
            if (m_sets != NULL)
                free(m_sets);
        }

        int size() {
            return m_count;
        }

        void insert(int x) {
            assert(m_sets != NULL);
            if (test(x))
                return ;
            set(x);
            m_count++;
        }

        bool lookup(int x) {
            return test(x);
        }

    private:
        enum { MASK          = 0x1F,
               SHIFT         = 5,
               BITS_PER_WORD = 32,
             };

        int m_size;
        int m_count;
        int *m_sets;

        void set(int x) {
            m_sets[x >> SHIFT] |= (1 << (x & MASK));
        }

        void clr(int x) {
            m_sets[x >> SHIFT] &= ~(1 << (x & MASK));
        }

        bool test(int x) {
            return m_sets[x >> SHIFT] & (1 << (x & MASK));
        }

        void clear() {
            for (int i = 0; i < m_size; i++)
                clr(i);
        }
};

#endif
