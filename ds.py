import re

def parse_sf_express_address(text):
    # 正则匹配规则
    patterns = {
        "province": r"([\u4e00-\u9fa5]{2,}省|[\u4e00-\u9fa5]{2,}自治区)",
        "city": r"([\u4e00-\u9fa5]{2,}市)",
        "district": r"([\u4e00-\u9fa5]{2,}区|[\u4e00-\u9fa5]{2,}县)",
        "detail": r"([\u4e00-\u9fa5\d\-号]+路?[\d\-号]+)"
    }
    
    address = {}
    # 第一步：提取省市区和初始详细地址
    for field, pattern in patterns.items():
        match = re.search(pattern, text)
        if match:
            address[field] = match.group(1)
            text = text.replace(match.group(1), "", 1)
    
    # 第二步：从剩余文本中提取电话和姓名
    remaining_text = text.strip()
    
    # 匹配电话号码（兼容带空格/短横线的情况）
    phone_re = r'(1[3-9]\d[\s\-]?\d{4}[\s\-]?\d{4})'
    phone_match = re.search(phone_re, remaining_text)
    if phone_match:
        address["phone"] = re.sub(r'[\s\-]', '', phone_match.group(1))  # 清洗电话格式
        remaining_text = remaining_text.replace(phone_match.group(1), "", 1)
    
    # 匹配中文姓名（2-4个汉字）
    name_re = r'([\u4e00-\u9fa5]{2,4})'
    name_match = re.search(name_re, remaining_text)
    if name_match:
        address["name"] = name_match.group(1)
        remaining_text = remaining_text.replace(name_match.group(1), "", 1)
    
    # 剩余内容作为详细地址补充
    address["detail"] = remaining_text.strip()
    return address

# 示例测试
text = input("请输入地址、姓名及联系电话：")
# 测试用例1: "中国广东省广州市番禺区广州大学城外环东路382号 张三 11451438000"
result = parse_sf_express_address(text)
print(result)