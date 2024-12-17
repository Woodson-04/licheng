#ifndef CUCKOO_HASH_TABLE_H
#define CUCKOO_HASH_TABLE_H

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename T>
class CuckooHashFamily
{
    public:
        size_t hash( const T &x ,int which ) const;
        int getNumberOfFunctions( );
        void generateNewFunctions( );
};

template <int count>
class StringHashFamily
{
    public:
        StringHashFamily( ) : MULTIPLIERS( count )
        {
            generateNewFunctions( );
        }

        int getNumberOfFunctions( ) const
        {
            return count;
        }

        void generateNewFunctions( )
        {
            for ( auto &mult : MULTIPLIERS )
                mult = r.nextInt( );
        }

        size_t hash( const string &x, int which ) const
        {
            const int multiplier = MULTIPLIERS[ which ];
            
        }
}