import re

def parse_sf_express_address(text):
    address = {}

    # 1. 提取電話號碼
    phone_re = r'(1[3-9]\d{9})'
    phone_match = re.search(phone_re, text)
    name = None

    if phone_match:
        phone = phone_match.group(1)
        address["phone"] = phone

        # 嘗試在電話前面找姓名（4個字以內）
        before = text[:phone_match.start()].strip()
        after = text[phone_match.end():].strip()

        name_re = r'([\u4e00-\u9fa5]{2,4})'

        name_match = re.search(name_re + r'$', before)  # 結尾是名字
        if not name_match:
            name_match = re.match(r'^' + name_re, after)  # 開頭是名字

        if name_match:
            name = name_match.group(1)
            address["name"] = name

        # 清理姓名和電話出現的部分
        text = text.replace(phone, "", 1)
        if name:
            text = text.replace(name, "", 1)

    # 2. 提取省、市、區縣
    patterns = {
        "province": r"(北京市|天津市|上海市|重庆市|[\u4e00-\u9fa5]{2,}省|[\u4e00-\u9fa5]{2,}自治区)",
        "city": r"([\u4e00-\u9fa5]{2,}市)",
        "district": r"([\u4e00-\u9fa5]{2,}(区|县))",
    }

    for field, pattern in patterns.items():
        match = re.search(pattern, text)
        if match:
            address[field] = match.group(1)
            text = text.replace(match.group(1), "", 1)

    # 3. 剩下的就是詳細地址
    address["detail"] = text.strip()

    return address



# 示例测试
text = input("请输入地址、姓名及联系电话：")
# 测试用例1: "广东省深圳市南山区科技园路1号 张三 13800138000"
# 测试用例2: "张三 13800138000 广东省深圳市南山区科技园路1号"
result = parse_sf_express_address(text)
print(result)