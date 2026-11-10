So sánh 2 cách tạo nhịp định kỳ:
 - delay(): Dùng vòng lặp blocking (chặn). CPU phải đứng chờ hết khoảng thời gian được yêu cầu, không làm được việc gì khác trong lúc đó.
 - millis(): Dùng cơ chế non-blocking (không chặn). Vòng lặp loop() chạy liên tục, mỗi tác vụ tự so sánh thời gian hiện tại (millis()) với mốc lần trước của chính nó để quyết định xem đã đến lúc thực hiện chưa
Đo khoảng thực tế và nhận xét độ ổn định:
 - delay(): Độ lệch rất lớn nếu có nhiều tác vụ gọi nối tiếp, vì tổng thời gian của một vòng lặp sẽ bằng tổng các khoảng delay cộng lại, khiến các tác vụ phía sau bị trễ nghiêm trọng.
 - millis(): Độ ổn định tương đối tốt nếu các tác vụ bên trong loop() ngắn và chạy nhanh. Tuy nhiên, nếu CPU bị bận xử lý một tác vụ nặng kéo dài, các mốc thời gian tiếp theo sẽ bị trôi (drift).
Khả năng bám nhịp khi "CPU bận":
 - Timer phần cứng: Bám nhịp tốt nhất khi CPU bận. Lý do: Nó hoạt động độc lập với loop(), ngắt phần cứng có độ ưu tiên cao sẽ tạm dừng công việc hiện tại của CPU để xử lý ngay khi đến chu kỳ.
 - millis(): Bám nhịp kém hơn khi CPU bận. Lý do: Phụ thuộc vào việc loop() quay vòng trở lại để kiểm tra điều kiện if (now - last >= interval). Nếu loop() đang bận xử lý việc khác, thời điểm phát hiện điều kiện sẽ bị chậm trễ.
