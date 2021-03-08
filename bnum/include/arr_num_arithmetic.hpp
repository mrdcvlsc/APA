#ifndef ARR_NUM_ARITHMETIC_HPP
#define ARR_NUM_ARITHMETIC_HPP

#include <string>
#include <vector>
#include <cmath>

typedef std::vector<short> arr_num;

namespace anum{

    inline char int_to_char(int digit)
    {
        return 48+digit;
    }

    inline short char_to_int(char letter)
    {
        return letter-48;
    }

    inline std::vector<short> create(const std::string& str_number)
    {
        size_t str_len = str_number.size();
        std::vector<short> new_arr;
        new_arr.reserve(str_len);
        for(size_t i=0; i<str_len; ++i)
        {
            new_arr.push_back(char_to_int(str_number[i]));
        }
        return new_arr;
    }

    inline std::vector<short> add(const std::vector<short>& upper_adden, const std::vector<short>& lower_adden)
    {
        size_t uadden_len = upper_adden.size();
        size_t ladden_len = lower_adden.size();

        size_t longest_len = std::max(uadden_len,ladden_len);
        size_t ans_len = longest_len;
        std::vector<short> index_sums(ans_len,0);								

        // operation
        for(size_t i=0 ;i<uadden_len; ++i){
            index_sums[ans_len-1-i]+=upper_adden[uadden_len-1-i];
        }
        
        for(size_t i=0 ;i<ladden_len; ++i){
            index_sums[ans_len-1-i]+=lower_adden[ladden_len-1-i];
        }

        // carry
        for(size_t i=ans_len-1ll; i>0; i--){
            if(index_sums[i]>9){	
                index_sums[i]=index_sums[i]-10;
                ++index_sums[i-1];
            }
        }

        // add new chunk if needed
        if(index_sums[0]>9){
            index_sums[0]=index_sums[0]-10;
            index_sums.insert(index_sums.begin(),1ll);
        }
        
        return index_sums;
    }

    inline std::vector<short> sub(const std::vector<short>& minuend, const std::vector<short>& subtrahend)
    {
        size_t minuend_len = minuend.size();
        size_t subtrah_len = subtrahend.size();

        size_t longest_len = std::max(minuend_len,subtrah_len);
        size_t ans_len = longest_len;
        std::vector<short> index_diff(ans_len,0);								

        // operation
        for(size_t i=0 ;i<minuend_len; ++i){
            index_diff[ans_len-1-i]=minuend[minuend_len-1-i];
        }
        
        for(size_t i=0 ;i<subtrah_len; ++i){
            index_diff[ans_len-1-i]-=subtrahend[subtrah_len-1-i];
        }

        // carry
        for(size_t i=ans_len-1ll; i>0; --i){
            if(index_diff[i]<0) {
                index_diff[i]=index_diff[i]+10;
                --index_diff[i-1];
            }
        }

        // check and remove zero chunks
        size_t chunk_to_remove = 0;
        size_t resulting_size = ans_len;
        for(size_t i=0; i<ans_len; ++i){
            if(index_diff[i]==0 && resulting_size>1){
                chunk_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(chunk_to_remove) index_diff.erase(index_diff.begin()+0,index_diff.begin()+chunk_to_remove);
        //
        return index_diff;
    }

    inline short one_thsd(short number, short tens){
        return number-(tens*10);
    }

    inline short ten_thsd(short number){
        return (short)floor((long double)number/10.0);
    }

    inline std::vector<short> mul(const std::vector<short>& multiplicand, const std::vector<short>& multiplier)
    {	
        // add the answer of the multiplicand and multiplier to the answer array
        size_t multiplicand_len = multiplicand.size();
        size_t multiplier_len = multiplier.size();

        // set all values of product to zero
        size_t product_length = multiplicand_len+multiplier_len; 
        std::vector<short> index_product(product_length,0);

        // operation
        for(size_t i=0ul; i<multiplier_len; ++i){
            for(size_t j=0ul;j<multiplicand_len;++j) {
                index_product[product_length-1-i-j] = index_product[product_length-1-i-j]+(multiplicand[multiplicand_len-1-j]*multiplier[multiplier_len-1-i]);
            }
        }

        // carry
        short ten;
        short one;
        for(size_t i=0ul;i<product_length;++i) {
            if(index_product[product_length-1-i]>=10) {
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
            if(index_product[i]==0 && resulting_size>1){
                chunk_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(chunk_to_remove) index_product.erase(index_product.begin()+0,index_product.begin()+chunk_to_remove);

        return index_product;
    }

    /// @def converts a std::vector<short> that have strictly only one digit per elements into a std::string representation
    /// @arg std::vector<short> arr - an array composed of single digit short integer
    /// @return returns a std::string
    inline std::string to_string(const std::vector<short>& arr){
        size_t arr_size = arr.size();
        std::string converted;
        converted.reserve(arr_size);
        for(size_t i=0; i<arr_size; ++i){
            converted.push_back(int_to_char(arr[i]));
        }
        return converted;
    }

    /// @return true if left is equal to right
    inline bool is_equal(const std::vector<short>& left, const std::vector<short>& right)
    {
        size_t left_size = left.size();
        size_t right_size = right.size();

        if(left_size==right_size)
        {
            for(size_t i=0; i<left_size; ++i)
            {
                if(left[i]!=right[i]) return false;
            }
            return true;
        }
        return false;
    }

    /// @return true if left is lessthan right
    inline bool is_less(const std::vector<short>& left, const std::vector<short>& right)
    {
        size_t left_size = left.size();
        size_t right_size = right.size();
        
        if(left_size>right_size) return false;
        else if(left_size<right_size) return true;
        else{
            for(size_t i=0; i<left_size; ++i)
            {
                if(left[i]<right[i]){
                    return true;
                }
                else if(left[i]>right[i])
                {
                    return false;
                }
            }
            return false;
        }
    }

    /// @return true if left is lessthan or equal to right 
    inline bool is_less_equal(const std::vector<short>& left, const std::vector<short>& right)
    {
        size_t left_size = left.size();
        size_t right_size = right.size();

        if(left_size>right_size)
        {
            return false;
        }
        else if(left_size<right_size)
        {
            return true;
        }
        else
        {
            for(size_t i=0; i<left_size; ++i)
            {
                if(left[i]<right[i]){
                    return true;
                }
                else if(left[i]>right[i])
                {
                    return false;
                }
            }
            return true;
        }
    }

    /// @arg arr - an array that contains single digit short integers
    /// @arg start_index - start index of the sub array you want to get
    /// @arg lenght - the included number of elements from start_index
    /// @returns sub array of the original array vector
    inline std::vector<short> sub_arr_il(const std::vector<short>& arr, size_t start_index, size_t length)
    {
        std::vector<short> sub_vector(arr.begin()+start_index,arr.begin()+(start_index+length));
        return sub_vector;
    }

    /// @arg arr - an array that contains single digit short integers
    /// @arg start_index - start index of the sub array you want to get
    /// @arg end_index - end index of the sub array you want to get
    /// @returns sub array of the original array vector
    inline std::vector<short> sub_arr_ii(const std::vector<short>& arr, size_t start_index, size_t end_index)
    {
        std::vector<short> sub_vector(arr.begin()+start_index,arr.begin()+1+end_index);
        return sub_vector;
    }

    /// @arg str - a std::string that should only contain numbers only characters
    /// @return a std::string with no sequential zeroes in the front
    inline std::string rmzero(const std::string& str)
    {
        size_t str_len = str.size();
        size_t zero_indecies = 0;

        if(str_len==1) return str;

        for(size_t i=0; i<str_len; ++i)
        {
            if(str[i]!='0')
            {
                break;
            }
            ++zero_indecies;
        }

        return str.substr(zero_indecies,str_len-zero_indecies);
    }

    /// @arg arr_chunks - a std::vector<long long int> that has an eight digit std::max value per element
    /// @return a std::string number representation of the array
    inline std::string chunk_to_str(const std::vector<long long int>& arr_chunks)
    {
        size_t n = arr_chunks.size();
        std::string carried_answer="", current_index;

        for(size_t i=0ll;i<n;++i)
        {
            current_index = std::to_string(arr_chunks[i]);
            std::string front_zeros(8-current_index.size(),'0');
            carried_answer+=(front_zeros+current_index);
        }

        return rmzero(carried_answer);
    }

}
#endif