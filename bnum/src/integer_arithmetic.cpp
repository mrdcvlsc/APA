#include <algorithm>
#include "arr_num_arithmetic.hpp"
#include "bnum.hpp"

using namespace std;

bnumfield addint(const bnumfield& upper_adden, const bnumfield& lower_adden)
{
	size_t uadden_len = upper_adden.size();
	size_t ladden_len = lower_adden.size();

	size_t longest_len = max(uadden_len,ladden_len);
	size_t ans_len = longest_len;
	bnumfield index_sums(ans_len,0);								

	// operation
	for(size_t i=0ll ;i<uadden_len; ++i){
		index_sums[ans_len-1-i]+=upper_adden[uadden_len-1-i];
	}
	
	for(size_t i=0ll ;i<ladden_len; ++i){
		index_sums[ans_len-1-i]+=lower_adden[ladden_len-1-i];
	}

	// carry
	for(size_t i=ans_len-1ll; i>0ll; i--){
		if(index_sums[i]>99999999ll){	
			index_sums[i]=index_sums[i]-100000000ll;
			++index_sums[i-1];
		}
	}

	// add new chunk if needed
	if(index_sums[0]>99999999ll){
		index_sums[0]=index_sums[0]-100000000ll;
		index_sums.insert(index_sums.begin(),1ll);
	}
	
	return index_sums;
}

bnumfield subnum(const bnumfield& minuend, const bnumfield& subtrahend, size_t point_place_limit)
{
	size_t minuend_len = minuend.size();
	size_t subtrah_len = subtrahend.size();

	size_t longest_len = max(minuend_len,subtrah_len);
	size_t ans_len = longest_len;
	size_t remove_limit = ans_len - point_place_limit;
	bnumfield index_diff(ans_len,0);								

	// operation
	for(size_t i=0ll ;i<minuend_len; ++i){
		index_diff[ans_len-1-i]=minuend[minuend_len-1-i];
	}
	
	for(size_t i=0ll ;i<subtrah_len; ++i){
		index_diff[ans_len-1-i]-=subtrahend[subtrah_len-1-i];
	}

	// carry
	for(size_t i=ans_len-1ll; i>0ll; --i){
		if(index_diff[i]<0ll) {
			index_diff[i]=index_diff[i]+100000000ll;
			--index_diff[i-1];
		}
	}

	// check and remove zero chunks
	size_t chunk_to_remove = 0;
	size_t resulting_size = ans_len;
	for(size_t i=0; i<ans_len; ++i){
		if(index_diff[i]==0 && resulting_size>1 && i<remove_limit-1){
			chunk_to_remove++;
			resulting_size--;
		}
		else break;
	}
	if(chunk_to_remove) index_diff.erase(index_diff.begin()+0,index_diff.begin()+chunk_to_remove);
	//
	return index_diff;
}

long long int one_thsd(long long int number, long long int tens){
	return number-(tens*100000000ll);
}

long long int ten_thsd(long long int number){
	return (long long int)floor((long double)number/100000000.0);
}

bnumfield mulint(const bnumfield& multiplicand, const  bnumfield& multiplier)
{	
	// add the answer of the multiplicand and multiplier to the answer array
	size_t multiplicand_len = multiplicand.size();
	size_t multiplier_len = multiplier.size();

	// set all values of product to zero
	size_t product_length = multiplicand_len+multiplier_len; 
	bnumfield index_product(product_length,0);

	// operation
	for(size_t i=0ul; i<multiplier_len; ++i){
		for(size_t j=0ul;j<multiplicand_len;++j) {
			index_product[product_length-1-i-j] = index_product[product_length-1-i-j]+(multiplicand[multiplicand_len-1-j]*multiplier[multiplier_len-1-i]);
		}
	}

	// carry
	long long int ten;
	long long int one;
	for(size_t i=0ul;i<product_length;++i) {
		if(index_product[product_length-1-i]>=100000000ll) {
			ten = ten_thsd(index_product[product_length-1-i]);
			one = one_thsd(index_product[product_length-1-i],ten);
			index_product[product_length-1-i]=one;
			index_product[product_length-1-i-1]=index_product[product_length-1-i-1]+ten;
		}
	}
	// remove fron zero chunks
	// check and remove zero chunks
	size_t chunk_to_remove = 0;
	size_t resulting_size = product_length;
	for(size_t i=0; i<product_length; ++i){
		if(index_product[i]==0 && resulting_size>2){
			chunk_to_remove++;
			resulting_size--;
		}
		else break;
	}
	if(chunk_to_remove) index_product.erase(index_product.begin()+0,index_product.begin()+chunk_to_remove);
	
	return index_product;
}

string divint(const bnumfield& dividenBIF, const  bnumfield& divisorBIF){

	bnumfield zero = {0,0};
	bnumfield one = {1};

	bnum temp;
	if(dividenBIF==divisorBIF) return "1";

	size_t len = dividenBIF.size();
	for(size_t i=0; i<len; ++i){
		if(dividenBIF[i]!=0) break;
		if(i==len-1) return {0};
	}
	if(divisorBIF==one){
		temp.set_bnum_field(dividenBIF);
		return temp.string_form();
	}

	// new division : start

	// create a arr_num type using the 8 chunk bintfields
	arr_num arr_dividen;
	arr_num arr_divisor;

	arr_dividen = anum::create(anum::chunk_to_str(dividenBIF));
	arr_divisor = anum::create(anum::chunk_to_str(divisorBIF));

	size_t dividen_size = arr_dividen.size();

	arr_num accumulator;
	arr_num remainders;

	accumulator.reserve(dividen_size);
	
	for(size_t i=0; i<dividen_size; ++i)
	{
		arr_num part_dividen;
		part_dividen.reserve(remainders.size()+1);
		part_dividen.insert(part_dividen.end(),remainders.begin(),remainders.end());
		part_dividen.push_back(arr_dividen[i]);

		int counts = 0;

		while(anum::is_less_equal(arr_divisor,part_dividen)){
			counts++;
			part_dividen = anum::sub(part_dividen,arr_divisor);
		}
		remainders = part_dividen;
		if(remainders.size()==1 && remainders[0]=='0') remainders.clear();
		accumulator.push_back(counts);
	}

	string quotient = anum::to_string(accumulator);
	return quotient;
}