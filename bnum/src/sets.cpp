#include "bnum.hpp"

using namespace std;

/// @param arg1_bnumfield a bnumfield(vector<long long int>)
/// @param arg2_start_index starting index of the subset in the original set
/// @param arg3_end_index end index  of the subset in the original set
/// @returns another subset of bnumfield type from the origial bnumfield set
bnumfield get_field_subset(const bnumfield& set, size_t istart, size_t iend){
	bnumfield newset;
	newset.reserve(iend-istart+1);
	newset.insert(newset.end(),set.begin()+istart,set.begin()+iend+1);
	return newset;
}

bnumfield join_field_sets(const bnumfield& left, const bnumfield& right){
	bnumfield joinedfield;
	joinedfield.reserve(left.size() + right.size());
	joinedfield.insert(joinedfield.end(), left.begin(), left.end());
	joinedfield.insert(joinedfield.end(), right.begin(), right.end());
	return joinedfield;
}