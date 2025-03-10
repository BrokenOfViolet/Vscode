# https://chat.openai.com/

import cv2
import dlib
import numpy as np
import face_recognition  # 需要安装 face_recognition 库

# 加载已知的人脸数据
known_face_encodings = []
known_face_names = []

# TODO: 将已知人脸的编码和姓名添加到 known_face_encodings 和 known_face_names 列表中

# 初始化摄像头
cap = cv2.VideoCapture(0)  # 0 表示默认摄像头

while True:
    ret, frame = cap.read()
    rgb_frame = frame[:, :, ::-1]  # 转换为 RGB 格式

    # 检测人脸
    face_locations = face_recognition.face_locations(rgb_frame)
    face_encodings = face_recognition.face_encodings(rgb_frame, face_locations)

    for face_encoding in face_encodings:
        # 尝试匹配检测到的人脸与已知人脸
        matches = face_recognition.compare_faces(known_face_encodings, face_encoding)
        name = "Unknown"

        # 找到匹配的人脸
        if True in matches:
            first_match_index = matches.index(True)
            name = known_face_names[first_match_index]

        # 标记人脸位置
        top, right, bottom, left = face_location
        cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)

        # 在人脸框下方显示姓名
        cv2.putText(frame, name, (left + 6, bottom - 6), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 1)

    # 显示结果
    cv2.imshow("Face Recognition", frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
