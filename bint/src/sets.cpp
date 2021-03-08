#include "bint.hpp"

using namespace std;

/// @param arg1_bintfield a bintfield(vector<long long int>)
/// @param arg2_start_index starting index of the subset in the original set
/// @param arg3_end_index end index  of the subset in the original set
/// @returns another subset of bintfield type from the origial bintfield set
bintfield get_field_subset(const bintfield& set, size_t istart, size_t iend){
	bintfield newset;
	newset.reserve(iend-istart+1);
	newset.insert(newset.end(),set.begin()+istart,set.begin()+iend+1);
	return newset;
}

bintfield join_field_sets(const bintfield& left, const bintfield& right){
	bintfield joinedfield;
	joinedfield.reserve(left.size() + right.size());
	joinedfield.insert(joinedfield.end(), left.begin(), left.end());
	joinedfield.insert(joinedfield.end(), right.begin(), right.end());
	return joinedfield;
}