#ifndef ADDRESS_H
#define ADDRESS_H

// Kết hợp string và mã hóa ID/Enum giúp tăng hiệu năng tìm kiếm, lưu trữ và giảm thiểu lỗi nhập dữ liệu không đồng nhất
class Address
{
    private:
    string HouseNumber;
    string Street;
    //
    int WardID;
    int DistrictID;    
    int ProvinceCityID;
    public:
    Address(string house_number, string street, int ward_id, int district_id, int province_city_id) : HouseNumber(house_number), Street(street), WardID(ward_id), DistrictID(district_id), ProvinceCityID(province_city_id)
    {
        // check for validation
        // Add thư viện mã hóa ID/Enum để kiểm tra tính hợp lệ của WardID, DistrictID, ProvinceCityID
    }
};
#endif