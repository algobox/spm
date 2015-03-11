#include "spm_bs2bm.h"

/**
 * \brief Array setup function for Bs2Bm of bad characters index (not found at the needle)
 *
 * \param neddle pointer to the pattern we ar searching for
 * \param needle_len length limit of the needle
 * \param badchars pointer to an empty array of bachars. The array prepared contains
 *                 characters that can't be inside the needle_len. So the skips can be
 *                 faster
 */
void Bs2BmBadchars(const uint8_t *needle, uint16_t needle_len, uint8_t *badchars)
{
    uint32_t i;
    for (i = 0; i < ALPHABET_SIZE; i++)
        badchars[i] = 1;

    /* set to 0 the values where index as ascii is present
     * because they are not badchars
     */
    for (i = 0; i < needle_len; i++)
        badchars[needle[i]] = 0;
}

/**
 * \brief Array setup function for Bs2BmNocase of bad characters index (not found at the needle)
 *
 * \param neddle pointer to the pattern we ar searching for
 * \param needle_len length limit of the needle
 * \param badchars pointer to an empty array of bachars. The array prepared contains
 *                 characters that can't be inside the needle_len. So the skips can be
 *                 faster
 */
void Bs2BmBadcharsNocase(const uint8_t *needle, uint16_t needle_len, uint8_t *badchars)
{
    uint32_t i;
    for (i = 0; i < ALPHABET_SIZE; i++)
        badchars[i] = 1;

    /* set to 0 the values where index as ascii is present
     * because they are not badchars
     */
    for (i = 0; i < needle_len; i++) {
        badchars[u8_tolower(needle[i])] = 0;
    }
}


/**
 * \brief Basic search with a bad characters array. The array badchars contains
 *        flags at character's ascii index that can't be inside the needle. So the skips can be
 *        faster
 *
 * \param haystack pointer to the buffer to search in
 * \param haystack_len length limit of the buffer
 * \param neddle pointer to the pattern we ar searching for
 * \param needle_len length limit of the needle
 * \param badchars pointer to an array of bachars prepared by Bs2BmBadchars()
 *
 * \retval ptr to start of the match; NULL if no match
 */
uint8_t * Bs2Bm(const uint8_t *haystack, uint32_t haystack_len, const uint8_t *needle, uint16_t needle_len, uint8_t badchars[])
{
    const uint8_t *h, *n;
    const uint8_t *hmax = haystack + haystack_len;
    const uint8_t *nmax = needle + needle_len;

    if (needle_len == 0 || needle_len > haystack_len)
        return NULL;

    for (n = needle; nmax - n <= hmax - haystack; haystack++) {
        if (*haystack != *n) {
            continue;
        }
        /* one byte needles */
        if (needle_len == 1)
            return (uint8_t *)haystack;

        for (h = haystack+1, n++; nmax - n <= hmax - haystack; h++, n++) {
            if (*h != *n) {
                if (badchars[*h] == 1) {
                    /* skip it! */
                    haystack = h;
                }
                break;
            }
            /* if we run out of needle we fully matched */
            if (n == nmax - 1 ) {
                return (uint8_t *)haystack;
            }
        }
        n = needle;
    }

    return NULL;
}

/**
 * \brief Basic search case less with a bad characters array. The array badchars contains
 *        flags at character's ascii index that can't be inside the needle. So the skips can be
 *        faster
 *
 * \param haystack pointer to the buffer to search in
 * \param haystack_len length limit of the buffer
 * \param neddle pointer to the pattern we ar searching for
 * \param needle_len length limit of the needle
 * \param badchars pointer to an array of bachars prepared by Bs2BmBadchars()
 *
 * \retval ptr to start of the match; NULL if no match
 */
uint8_t *Bs2BmNocase(const uint8_t *haystack, uint32_t haystack_len, const uint8_t *needle, uint16_t needle_len, uint8_t badchars[])
{
    const uint8_t *h, *n;
    const uint8_t *hmax = haystack + haystack_len;
    const uint8_t *nmax = needle + needle_len;

    if (needle_len == 0 || needle_len > haystack_len)
        return NULL;

    for (n = needle; nmax - n <= hmax - haystack; haystack++) {
        if (u8_tolower(*haystack) != u8_tolower(*n)) {
            continue;
        }
        /* one byte needles */
        if (needle_len == 1)
            return (uint8_t *)haystack;

        for (h = haystack+1, n++; nmax - n <= hmax - haystack; h++, n++) {
            if (u8_tolower(*h) != u8_tolower(*n)) {
                if (badchars[u8_tolower(*h)] == 1) {
                    /* skip it! */
                    haystack = h;
                }
                break;
            }
            /* if we run out of needle we fully matched */
            if (n == nmax - 1) {
                return (uint8_t *)haystack;
            }
        }
        n = needle;
    }

    return NULL;
}
