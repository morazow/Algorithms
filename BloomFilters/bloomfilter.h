#ifndef __BLOOMFILTER_H__
#define __BLOOMFILTER_H__

#include "bitvector.h"
#include <stdarg.h>
#include <vector>

typedef int (*hfunc_t)(const char *);

class BloomFilter {
    public:
        BloomFilter(int size, int K, ...) {
            m_size = size;
            assert(m_size > 0);

            m_bitvector = new BitVector(size);
            assert(m_bitvector != NULL);

            assert(K > 0);
            m_hashes.reserve(K);

            va_list L;
            va_start(L, K);
            for (int i = 0; i < K; i++) {
                m_hashes[i] = va_arg(L, hfunc_t);
            }
            va_end(L);

        }

        ~BloomFilter() {
            delete m_bitvector;
        }

        void insert(const char *key) {
            for (size_t i = 0; i < m_hashes.size(); i++)
                m_bitvector->insert(m_hashes[i](key) % m_size);
        }

        bool lookup(const char *key) {
            for (size_t i = 0; i < m_hashes.size(); i++)
                if ( !m_bitvector->lookup(m_hashes[i](key) % m_size) )
                    return false;
            return true;
        }

    private:
        int m_size;
        BitVector *m_bitvector;

        std::vector<hfunc_t> m_hashes;
};

#endif
