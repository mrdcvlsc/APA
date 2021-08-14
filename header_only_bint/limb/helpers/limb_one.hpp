#ifndef LIMB_ONE_HPP
#define LIMB_ONE_HPP

#include <string>
#include <vector>
#include <cmath>

namespace limb_one{

    typedef std::vector<int8_t> num;

    inline char int_to_char(int digit)
    {
        return ((int8_t)'0')+digit;
    }

    inline int8_t char_to_int(char letter)
    {
        return letter-((int8_t)'0');
    }

    inline std::vector<int8_t> create(const std::string& str_number)
    {
        size_t str_len = str_number.size();
        std::vector<int8_t> new_arr;
        new_arr.reserve(str_len);
        for(size_t i=0; i<str_len; ++i)
        {
            new_arr.push_back(char_to_int(str_number[i]));
        }
        return new_arr;
    }

    inline std::vector<int8_t> add(const std::vector<int8_t>& upper_adden, const std::vector<int8_t>& lower_adden)
    {
        size_t uadden_len = upper_adden.size();
        size_t ladden_len = lower_adden.size();

        size_t longest_len = std::max(uadden_len,ladden_len);
        size_t ans_len = longest_len;
        std::vector<int8_t> index_sums(ans_len,0);								

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

        // add new limb if needed
        if(index_sums[0]>9){
            index_sums[0]=index_sums[0]-10;
            index_sums.insert(index_sums.begin(),1ll);
        }
        
        return index_sums;
    }

    inline std::vector<int8_t> sub(const std::vector<int8_t>& minuend, const std::vector<int8_t>& subtrahend)
    {
        size_t minuend_len = minuend.size();
        size_t subtrah_len = subtrahend.size();

        size_t longest_len = std::max(minuend_len,subtrah_len);
        size_t ans_len = longest_len;
        std::vector<int8_t> index_diff(ans_len,0);								

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

        // check and remove zero limbs
        size_t limb_to_remove = 0;
        size_t resulting_size = ans_len;
        for(size_t i=0; i<ans_len; ++i){
            if(index_diff[i]==0 && resulting_size>1){
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove) index_diff.erase(index_diff.begin()+0,index_diff.begin()+limb_to_remove);
        //
        return index_diff;
    }

    inline int8_t one_thsd(int8_t number, int8_t tens){
        return number-(tens*10);
    }

    inline int8_t ten_thsd(int8_t number){
        return (int8_t)floor((long double)number/10.0);
    }

    inline std::vector<int8_t> mul(const std::vector<int8_t>& multiplicand, const std::vector<int8_t>& multiplier)
    {	
        // add the answer of the multiplicand and multiplier to the answer array
        size_t multiplicand_len = multiplicand.size();
        size_t multiplier_len = multiplier.size();

        // set all values of product to zero
        size_t product_length = multiplicand_len+multiplier_len; 
        std::vector<int8_t> index_product(product_length,0);

        // operation
        for(size_t i=0ul; i<multiplier_len; ++i){
            for(size_t j=0ul;j<multiplicand_len;++j) {
                index_product[product_length-1-i-j] = index_product[product_length-1-i-j]+(multiplicand[multiplicand_len-1-j]*multiplier[multiplier_len-1-i]);
            }
        }

        // carry
        int8_t ten;
        int8_t one;
        for(size_t i=0ul;i<product_length;++i) {
            if(index_product[product_length-1-i]>=10) {
                ten = ten_thsd(index_product[product_length-1-i]);
                one = one_thsd(index_product[product_length-1-i],ten);
                index_product[product_length-1-i]=one;
                index_product[product_length-1-i-1]=index_product[product_length-1-i-1]+ten;
            }
        }

        // remove fron zero limbs
        // check and remove zero limbs
        size_t limb_to_remove = 0;
        size_t resulting_size = product_length;
        for(size_t i=0; i<product_length; ++i){
            if(index_product[i]==0 && resulting_size>1){
                limb_to_remove++;
                resulting_size--;
            }
            else break;
        }
        if(limb_to_remove) index_product.erase(index_product.begin()+0,index_product.begin()+limb_to_remove);

        return index_product;
    }

    /// @def converts a std::vector<int8_t> that have strictly only one digit per elements into a std::string representation
    /// @arg std::vector<int8_t> arr - an array composed of single digit int8_t integer
    /// @return returns a std::string
    inline std::string to_string(const std::vector<int8_t>& arr){
        size_t arr_size = arr.size();
        std::string converted;
        converted.reserve(arr_size);
        for(size_t i=0; i<arr_size; ++i){
            converted.push_back(int_to_char(arr[i]));
        }
        return converted;
    }

    /// @return true if left is equal to right
    inline bool is_equal(const std::vector<int8_t>& left, const std::vector<int8_t>& right)
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
    inline bool is_less(const std::vector<int8_t>& left, const std::vector<int8_t>& right)
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
        }
        return false;
    }

    /// @return true if left is lessthan or equal to right 
    inline bool is_less_equal(const std::vector<int8_t>& left, const std::vector<int8_t>& right)
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
        }
        return true;
    }

    /// @arg arr - an array that contains single digit int8_t integers
    /// @arg start_index - start index of the sub array you want to get
    /// @arg lenght - the included number of elements from start_index
    /// @returns sub array of the original array vector
    inline std::vector<int8_t> sub_arr_il(const std::vector<int8_t>& arr, size_t start_index, size_t length)
    {
        std::vector<int8_t> sub_vector(arr.begin()+start_index,arr.begin()+(start_index+length));
        return sub_vector;
    }

    /// @arg arr - an array that contains single digit int8_t integers
    /// @arg start_index - start index of the sub array you want to get
    /// @arg end_index - end index of the sub array you want to get
    /// @returns sub array of the original array vector
    inline std::vector<int8_t> sub_arr_ii(const std::vector<int8_t>& arr, size_t start_index, size_t end_index)
    {
        std::vector<int8_t> sub_vector(arr.begin()+start_index,arr.begin()+1+end_index);
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

    /// @arg arr_limbs - a std::vector<T> that has an eight digit std::max value per element
    /// @return a std::string number representation of the array
    template<typename T>
    inline std::string limb_to_str(const std::vector<T>& arr_limbs, size_t given_limb_len)
    {
        size_t n = arr_limbs.size();
        std::string carried_answer="", current_index;

        for(size_t i=0ll;i<n;++i)
        {
            current_index = std::to_string(arr_limbs[i]);
            std::string front_zeros(given_limb_len-current_index.size(),'0');
            carried_answer+=(front_zeros+current_index);
        }

        return rmzero(carried_answer);
    }

}
#endif