#include "bnum.hpp"

bool chunk_is_equal(const bnumfield& left_field,const bnumfield& right_field){
    size_t left_size = left_field.size();
    size_t right_size = right_field.size();

    if(left_size==right_size){
        for(size_t i=0; i<left_size; ++i){
            if(left_field[i]!=right_field[i])
                return false;
        }
        return true;
    }
    else return false;
}

bool chunk_is_not_equal(const bnumfield& left_field,const bnumfield& right_field){
    return !(chunk_is_equal(left_field,right_field));
}

/// compares absolute values of chunks
bool chunk_is_less(const bnumfield& left_field,const bnumfield& right_field){
    if(chunk_is_equal(left_field,right_field)) return false;
    size_t left_size = left_field.size();
    size_t right_size = right_field.size();
    if(left_size<right_size) return true;
    else if(left_size>right_size) return false;
    else{
        for(size_t i=0; i<left_size; ++i){
            if(left_field[i]<right_field[i])
                return true;
            else if(left_field[i]>right_field[i])
                return false;
        }
        return false;
    }
}

bool chunk_is_great(const bnumfield& left_field,const bnumfield& right_field){
    if(chunk_is_equal(left_field,right_field))
        return false;
    return !(chunk_is_less(left_field,right_field));
}

bool chunk_is_less_equal(const bnumfield& left_field,const bnumfield& right_field){
    if(chunk_is_equal(left_field,right_field))
        return true;
    return chunk_is_less(left_field,right_field);
}

bool chunk_is_great_equal(const bnumfield& left_field,const bnumfield& right_field){
    if(chunk_is_equal(left_field,right_field))
        return true;
    return chunk_is_great(left_field,right_field);
}

bool bnum::operator==(const bnum& that) const // base comparison operator - use to create other comparison operators
{
    if(this->sign!=that.sign) return false;

    long long int left_whole = this->point_place * this->sign;
    long long int right_whole = that.point_place * that.sign; 

    if(left_whole!=right_whole) return false;

    size_t left_len = this->integer.size();
    size_t right_len = that.integer.size();

    if(left_len==right_len){
        for(size_t i=0; i<left_len; ++i){
            if(this->integer[left_len-1-i]!=that.integer[right_len-1-i])
                return false;
        }
        return true;
    }
    return false; 
}

bool bnum::operator!=(const bnum& that) const{ // base comparison operator  - use to create other comparison operators
	return !(*this==that);
}

bool bnum::operator< (const bnum& that) const
{
    if(*this==that) return false;

    if((this->sign)<that.sign) return true;
    else if(this->sign>that.sign) return false;

    long long int left_whole = this->point_place * this->sign;
    long long int right_whole = that.point_place * that.sign; 

    if(left_whole>right_whole) return false;
    else if(left_whole<right_whole) return true;

    long long int left_len = (long long int)this->chunk_size();
    long long int right_len = (long long int)that.chunk_size();

    long long int left_points = left_len * (long long int)(this->sign);
    long long int right_points = right_len * (long long int)that.sign;
    
    long long int left_val, right_val;
    if(left_points==right_points){
        for(long long int i=0; i<left_len; ++i){
            left_val = (this->integer[i]*this->sign);
            right_val = (that.integer[i]*that.sign); 
            if(left_val>right_val) return false;
            else if(left_val<right_val) return true;
        }
        return false;
    }
    else if(left_points<right_points) return true;
    else return false; 
}

bool bnum::operator>(const bnum& that) const{
	if(*this==that)
		return false;
	return !(*this<that);
}

bool bnum::operator<=(const bnum& that) const{
	if(*this==that)
		return true;
	return *this<that;
}

bool bnum::operator>=(const bnum& that) const{	
	if(*this==that)
		return true;
	return *this>that;
}