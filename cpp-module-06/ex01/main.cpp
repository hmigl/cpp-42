/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmigl <hmigl@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:39:34 by hmigl             #+#    #+#             */
/*   Updated: 2023/04/11 11:01:56 by hmigl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./Serializer.hpp"

int main() {
  Data *data = new Data();

  data->lyrics =
      "Oh, life is bigger It's bigger Than you and you are not me The lengths "
      "that I will go to The distance in your eyes Oh no, I've said too much I "
      "set it up That's me in the corner That's me in the spotlight Losing my "
      "religion Trying to keep up with you And I don't know if I can do it Oh "
      "no, I've said too much I haven't said enough I thought that I heard you "
      "laughing I thought that I heard you sing I think I thought I saw you "
      "try Every whisper Of every waking hour I'm choosing my confessions "
      "Trying to keep an eye on you Like a hurt lost and blinded fool, fool Oh "
      "no, I've said too much I set it up Consider this Consider this The hint "
      "of the century Consider this The slip that brought me To my knees "
      "failed What if all these fantasies Come flailing around Now I've said "
      "too much I thought that I heard you laughing I thought that I heard you "
      "sing I think I thought I saw you try But that was just a dream That was "
      "just a dream That's me in the corner That's me in the spotlight Losing "
      "my religion Trying to keep up with you And I don't know if I can do it "
      "Oh no, I've said too much I haven't said enough I thought that I heard "
      "you laughing I thought that I heard you sing I think I thought I saw "
      "you try But that was just a dream Try, cry Why try? That was just a "
      "dream, just a dream, just a dream Dream";
  data->clipSeconds = 294;

  std::cout << "Before serialization: \n";
  std::cout << "lyrics: " << data->lyrics << std::endl;
  std::cout << "clipSeconds: " << data->clipSeconds << std::endl;
  std::cout << std::endl;

  uintptr_t serializedData = Serializer::serialize(data);
  Data *deserializedData = Serializer::deserialize(serializedData);

  std::cout << "After serialization: \n";
  std::cout << "lyrics: " << deserializedData->lyrics << std::endl;
  std::cout << "clipSeconds: " << deserializedData->clipSeconds << std::endl;
  delete data;
  return 0;
}
