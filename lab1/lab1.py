import cv2 as cv

img = cv.imread("lena.jpg")
cv.imshow("title xD",img)
cv.waitKey(0)

cv.destroyAllWindows() 
del img

img = cv.imread("lena.jpg",2)
cv.imshow("title xD",img)
cv.waitKey(0)
cv.destroyAllWindows() 
