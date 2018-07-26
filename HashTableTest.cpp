/*==- test/unittests/adt/HashTableTest.cpp ---------------------------------==

  This file is part of the Lity project distributed under GPL-3.0.
  See LICENSE for details.

==------------------------------------------------------------------------==*/
#include <adt/HashTable.h>
#include <cassert>

using namespace adt;

namespace {

struct PtrHash
{
  size_t operator()(const int* pKey) const
  {
    return (unsigned((uintptr_t)pKey) >> 4) ^
           (unsigned((uintptr_t)pKey) >> 9);
  }
};

struct IntHash
{
  size_t operator()(int pKey) const { return pKey; }
};

struct FixHash
{
  size_t operator()(int pKey) const { return 10; }
};

} // anonymous namespace

/*==------------------------------------------------------------------------==
  HashTableTest
==------------------------------------------------------------------------==*/
int main(int argc, char* argv[])
{
  HashTable<int*, int, PtrHash> hash(0);

  bool exist;
  HashTable<int*, int, PtrHash>::entry_type* entry = 0;

  int A = 1;
  int* pA = &A; 
  entry = hash.insert(pA, exist);

  assert(!hash.empty());

  HashTable<int*, int, PtrHash>::const_iterator iter;
  iter = hash.find(NULL);
  assert(iter == hash.end());
}
